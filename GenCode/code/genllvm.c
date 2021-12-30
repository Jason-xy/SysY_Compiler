#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "genllvm.h"

char buffer[500];
FILE *out;
int scope = 0;
int nextLoop = 0;
int finalLoop = 0;

int getVarNum()
{
    static int num = 0;
    return ++num;
}

void printLine()
{
    for (int i = 0; i < scope; i++)
        fprintf(out, "  ");
    fprintf(out, "%s\n", buffer);
}

void printLabel(int num)
{
    fprintf(out, ";<label>: %d\n", num);
}

void printEmptyLine()
{
    fprintf(out, "\n");
}

void genRoot(Ast *root)
{
    for (Ast *child = root->child; child != NULL; child = child->sibling)
    {
        if (child->nodeType == NT_STMT_VARDECL)
        {
            genGlobalVarDecl(child);
        }
        else if (child->nodeType == NT_STMT_CONSTDECL)
        {
            genGlobalConstDecl(child);
        }
        else if (child->nodeType == NT_STMT_FUNCDEF)
        {
            genFuncDef(child);
        }
    }
}

void genGlobalVarDecl(Ast *root)
{
    Ast *var = root->child->child;
    while (var != NULL)
    {
        if (var->nodeType == NT_VAR)
        {
            sprintf(buffer, "@%s = global i32, align 4", var->message);
            printLine();
        }
        else if (var->nodeType == NT_OP_ASSIGN)
        {
            Ast *id = var->child;
            Ast *value = id->sibling;
            if (id->nodeType == NT_VAR)
            {
                sprintf(buffer, "@%s = global i32 %d, align 4", id->message, value->value);
                printLine();
            }
        }
        var = var->sibling;
    }
}

void genGlobalConstDecl(Ast *root)
{
    Ast *var = root->child->child;
    while (var != NULL)
    {
        Ast *id = var->child;
        Ast *value = id->sibling;
        if (id->nodeType == NT_VAR)
        {
            sprintf(buffer, "@%s = global i32 %d, align 4", id->message, value->value);
            printLine();
        }
        var = var->sibling;
    }
}

void genFuncDef(Ast *root)
{
    printEmptyLine();
    Ast *funcType = root->child;
    Ast *funcName = funcType->sibling;
    Ast *block, *params;
    if (funcName->sibling->nodeType == NT_PARAM)
    {
        params = funcName->sibling;
        block = params->sibling;
        char tmp[50] = {0};
        int length = 0;
        for (Ast *param = params->child; param != NULL; param = param->sibling)
        {
            sprintf(tmp + length, "i32 %%%s,", param->child->sibling->message);
            length = strlen(tmp);
        }
        tmp[length - 1] = 0;
        sprintf(buffer, "define %s @%s(%s) #0 {", 
            funcType->message[0] == 'i' ? "i32" : "void"
            , funcName->message, tmp);
        printLine();
        scope++;

        genBlock(block);

        scope--;
        sprintf(buffer, "}");
        printLine();
    }
    else
    {
        block = funcName->sibling;
        sprintf(buffer, "define %s @%s() #0 {", 
            funcType->message[0] == 'i' ? "i32" : "void"
            , funcName->message);
        printLine();
        scope++;

        genBlock(block);

        scope--;
        sprintf(buffer, "}");
        printLine();
    }
}

void genBlock(Ast *root)
{
    Ast *stmt = root->child;
    Ast *var;
    Ast *lval, *expr;
    int rnum;
    while (stmt != NULL)
    {
        switch (stmt->nodeType)
        {
        case NT_STMT_VARDECL:
        case NT_STMT_CONSTDECL:
            var = stmt->child->child;
            while (var != NULL)
            {
                if (var->nodeType == NT_VAR)
                {
                    sprintf(buffer, "%%%s = alloca i32, align 4", var->message);
                    printLine();
                }
                else if (var->nodeType == NT_OP_ASSIGN)
                {
                    Ast *id = var->child;
                    Ast *value = id->sibling;
                    if (id->nodeType == NT_VAR)
                    {
                        sprintf(buffer, "%%%s = alloca i32, align 4", id->message);
                        printLine();
                        sprintf(buffer, "store i32 %d, i32 * %%%s, align 4", value->value, id->message);
                        printLine();
                    }
                }
                var = var->sibling;
            }
            break;
        case NT_OP_ASSIGN:
            lval = stmt->child;
            expr = lval->sibling;
            rnum = genExpr(expr);
            sprintf(buffer, "store i32 %%%d, i32 * %%%s, align 4", rnum, lval->message);
            printLine();
            break;
        case NT_FUNCCALL:
            genFuncCall(stmt);
            break;
        case NT_STMT_IFELSE:
            genIfElse(stmt);
            break;
        case NT_STMT_WHILE:
            genWhile(stmt);
            break;
        case NT_STMT_BREAK:
            sprintf(buffer, "br label %%%d", finalLoop);
            printLine();
            break;
        case NT_STMT_CONTINUE:
            sprintf(buffer, "br label %%%d", nextLoop);
            printLine();
            break;
        case NT_STMT_RETURN:
            expr = stmt->child;
            if (expr == NULL)
            {
                sprintf(buffer, "ret");
                printLine();
            }
            else
            {
                rnum = genExpr(expr);
                sprintf(buffer, "ret i32 %%%d", rnum);
                printLine();
            }
        default:
            break;
        }
        stmt = stmt->sibling;
    }
}

int genExpr(Ast *root)
{
    int ret = 0;
    int lnum, rnum;
    Ast *left, *right;
    switch (root->nodeType)
    {
    case NT_VAR:
        sprintf(buffer, "%%%d = load i32 * %%%s, align 4", ret = getVarNum(), root->message);
        printLine();
        break;
    case NT_CONSTANT:
        sprintf(buffer, "%%%d = i32 %d, align 4", ret = getVarNum(), root->value);
        printLine();
        break;
    case NT_FUNCCALL:
        ret = genFuncCall(root);
        break;
    case NT_OP_ADD:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = add nsw i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_SUB:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = sub nsw i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_MUL:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = mul nsw i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_DIV:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = div nsw i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_MOD:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = mod nsw i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_L:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp slt i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_LE:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp sle i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_G:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp sgt i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_GE:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp sge i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_E:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp seq i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_NE:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp sne i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_AND:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp and i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_OR:
        left = root->child;
        right = left->sibling;
        lnum = genExpr(left);
        rnum = genExpr(right);
        sprintf(buffer, "%%%d = icmp sor i32 %%%d, %%%d", ret = getVarNum(), lnum, rnum);
        printLine();
        break;
    case NT_OP_NOT:
        left = root->child;
        lnum = genExpr(left);
        sprintf(buffer, "%%%d = icmp not i32 %%%d", ret = getVarNum(), lnum);
        printLine();
        break;
    default:
        break;
    }
    return ret;
}

int genFuncCall(Ast *root)
{
    Ast *funcName = root->child;
    Ast *params = funcName->sibling;
    char tmp[50] = {0};
    int length = 0;
    if (params != NULL) 
    {
        for (Ast *param = params->child; param != NULL; param = param->sibling)
        {
            int num = genExpr(param);
            sprintf(tmp + length, "i32 %%%d,", num);
            length = strlen(tmp);
        }
        tmp[length - 1] = 0;
    }
    int ret = getVarNum();
    sprintf(buffer, "%%%d = call i32 @%s(%s)", ret, funcName->message, tmp);
    printLine();
    return ret;
}

void genIfElse(Ast *root)
{
    Ast *cond = root->child;
    Ast *ifStmt = cond->sibling;
    Ast *elseStmt = ifStmt->sibling;
    int condNum = genExpr(cond);
    int ifNum = getVarNum();
    int elseNum = getVarNum();
    sprintf(buffer, "br i1 %%%d, label %%%d, label %%%d", condNum, ifNum, elseNum);
    printLine();

    printEmptyLine();
    printLabel(ifNum);
    genBlock(ifStmt);
    if (elseStmt == NULL)
    {
        sprintf(buffer, "br label %%%d", elseNum);
        printLine();
        printEmptyLine();
        printLabel(elseNum);
    }
    else
    {
        int finalNum = getVarNum();
        sprintf(buffer, "br label %%%d", finalNum);
        printLine();
        printEmptyLine();
        printLabel(elseNum);
        genBlock(elseStmt);
        sprintf(buffer, "br label %%%d", finalNum);
        printLine();
        printEmptyLine();
        printLabel(finalNum);
    }
}

void genWhile(Ast *root)
{
    Ast *cond = root->child;
    Ast *body = cond->sibling;
    int loopNum = getVarNum();
    int bodyNum = getVarNum();
    int finalNum = getVarNum();
    nextLoop = loopNum;
    finalLoop = finalNum;
    printEmptyLine();
    printLabel(loopNum);
    int condNum = genExpr(cond);
    sprintf(buffer, "br i1 %%%d, label %%%d, label %%%d", condNum, bodyNum, finalNum);
    printLine();
    printEmptyLine();
    printLabel(bodyNum);
    genBlock(body);
    sprintf(buffer, "br label %%%d", loopNum);
    printLine();
    printEmptyLine();
    printLabel(finalNum);
}