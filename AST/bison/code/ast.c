#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyout;
extern int lineno;

past astHead;
//
past newAstNode()
{
    past node = checkMalloc();
    memset(node, 0, sizeof(ast));
    node->line = lineno;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

past checkMalloc()
{
    past node = (past)malloc(sizeof(ast));
    if (node == NULL)
    {
        log("run out of memory\n");
        exit(0);
    }
    return node;
}
//
past newList(past list, past node)
{
    if (list != NULL)
    {
        list->right->next = node;
        list->right = node;
        list->ivalue += 1;
        return list;
    }
    list = newAstNode();
    list->next = node;
    list->ivalue = 1;
    list->left = node;
    list->right = node;
    return list;
}

//
past newNumber(int ivalue)
{
    past node = newAstNode();
    node->nodeType = "NUMBER";
    node->ivalue = ivalue;
    return node;
}
//
past newString(char *evalue)
{
    past node = newAstNode();
    node->nodeType = "STRING";
    node->evalue = evalue;
    return node;
}
//
past newExpr(int oper, past left, past right)
{
    past node = newAstNode();
    node->nodeType = "expr";
    node->ivalue = oper;
    node->left = left;
    node->right = right;
    return node;
}

//!

past newFuncRParams(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "FuncRParams";
    return list;
}

past newUnaryExp(int op, past left, past right)
{
    past node = newAstNode();
    node->nodeType = "UnaryExp";
    node->ivalue = op;
    node->left = left;
    node->right = right;
    return node;
}

past newExps(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "Exps";
    return list;
}

past newLval(past left, past right)
{
    past node = newAstNode();
    node->nodeType = "LVal";
    node->left = left;
    node->right = right;
    return node;
}
// mew
past whileStmt(past cond, past stmt)
{
    past node = newAstNode();
    node->nodeType = "WhileStmt";
    node->left = cond;
    node->right = stmt;
    return node;
}

past exprStmt(past expr)
{
    past node = newAstNode();
    node->nodeType = "ExprStmt";
    node->left = expr;
    return node;
}

past lvalStmt(past left, past right)
{
    past node = newAstNode();
    node->nodeType = "LValStmt";
    node->left = left;
    node->right = right;
    return node;
}

past ifStmt(past cond, past stmt, past elseStmt)
{
    past node = newAstNode();
    node->nodeType = "IfStmt";
    node->left = cond;
    node->right = stmt;
    node->evalue = (char *)elseStmt;
    return node;
}

past returnStmt(past expr)
{
    past node = newAstNode();
    node->nodeType = "ReturnStmt";
    node->left = expr;
    return node;
}

past breakStmt()
{
    past node = newAstNode();
    node->nodeType = "BreakStmt";
    return node;
}

past continueStmt()
{
    past node = newAstNode();
    node->nodeType = "ContinueStmt";
    return node;
}

past newBlock(past left)
{
    past node = newAstNode();
    node->nodeType = "Block";
    node->left = left;
}

past newBlockItems(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "BlockItems";
    return list;
}

past newFuncFParam(int x, past left, past right)
{
    past node = newAstNode();
    node->nodeType = "FuncFParam";
    node->ivalue = x;
    node->left = left;
    node->right = right;
    return node;
}

past newFuncFParams(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "newFuncFParams";
    return list;
}

past newDeclarator(past left, past right)
{
    past node = newAstNode();
    node->nodeType = "Declarator";
    node->left = left;
    node->right = right;
    return node;
}

past newFuncDef(int x, past left, past right)
{
    past node = newAstNode();
    node->nodeType = "FuncDef";
    node->ivalue = x;
    node->left = left;
    node->right = right;
    return node;
}
//!
past newInitVal(past left)
{
    past node = newAstNode();
    node->nodeType = "InitVal";
    node->left = left;
    return node;
}
past newInitVals(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "InitVals";
    return list;
}
past newVarDef(int x, past left, past right, past init)
{
    past node = newAstNode();
    node->nodeType = "VarDef";
    node->ivalue = x;
    node->left = left;
    node->right = right;
    node->evalue = (char *)init;
    return node;
}

past newVarDefs(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "VarDefs";
    return list;
}

// past newVarDecl(past left)
// {
//     past node = newAstNode();
//     node->nodeType = "VarDecl";
//     node->left = left;
//     return node;
// }
// 与 newinitVal差不多
past newConstInitVal(past left)
{
    past node = newAstNode();
    node->nodeType = "ConstInitVal";
    node->left = left;
    return node;
}
past newConstInitVals(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "ConstInitVals";
    return list;
}

past newConstExps(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "ConstExps";
    return list;
}
past newConstDef(past left, past right, past init)
{
    past node = newAstNode();
    node->nodeType = "ConstDef";
    node->left = left;
    node->right = right;
    node->evalue = (char *)init;
    return node;
}

past newConstDefs(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "ConstDefs";
    return list;
}

past newConstDecl(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "ConstDecl";
    return list;
}
past newCompUnit(past left, past right)
{
    past list = newList(right, left);
    list->nodeType = "CompUnit";
    return list;
}

void showAst(past node, int nest)
{
    if (node == NULL)
        return;

    log("| ");
    if (nest == 0)
    {
        log("-");
    }
    else
    {
        int count = nest;
        while (count--)
        {
            log("| ");
        }
    }

    if (strcmp(node->nodeType, "NUMBER") == 0)
        log("num: %d\n", node->ivalue);
    else if (strcmp(node->nodeType, "STRING") == 0)
        log("id: %s\n", node->evalue);
    else if (strcmp(node->nodeType, "expr") == 0)
    {
        switch (node->ivalue)
        {
        case tok_LESS:
            log("%s <\n", node->nodeType);
            break;
        case tok_LESSEQ:
            log("%s <=\n", node->nodeType);
            break;
        case tok_GREAT:
            log("%s >\n", node->nodeType);
            break;
        case tok_GREATEQ:
            log("%s >=\n", node->nodeType);
            break;
        case tok_NOTEQ:
            log("%s !=\n", node->nodeType);
            break;
        case tok_EQ:
            log("%s ==\n", node->nodeType);
            break;
        case tok_OR:
            log("%s ||\n", node->nodeType);
            break;
        case tok_AND:
            log("%s &&\n", node->nodeType);
            break;
        default:
            log("%s %c\n", node->nodeType, (char)node->ivalue);
            break;
        }
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "FuncRParams") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }
    else if (strcmp(node->nodeType, "UnaryExp") == 0)
    {
        if (node->ivalue == (-1))
            log("%s\n", node->nodeType);
        else
            log("%s %c\n", node->nodeType, (char)node->ivalue);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "Exps") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "LVal") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "WhileStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "ExprStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "LValStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "IfStmt") == 0)
    {
        log("%s \n", node->nodeType);
        showAst((past)node->evalue, nest + 1);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "ReturnStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "BreakStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "ContinueStmt") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "Block") == 0)
    {
        log("%s\n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "BlockItems") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "FuncFParam") == 0)
    {
        if (node->ivalue == 0)
        {
            log("%s \n", node->nodeType);
        }
        else if (node->ivalue == 1)
        {
            log("%s []\n", node->nodeType);
        }
        else if (node->ivalue == 2)
        {
            log("%s \n", node->nodeType);
        }
        else if (node->ivalue == 3)
        {
            log("%s []\n", node->nodeType);
        }
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }
    else if (strcmp(node->nodeType, "newFuncFParams") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "Declarator") == 0)
    {
        log("%s \n", node->nodeType);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "FuncDef") == 0)
    {
        log("%s %c\n", node->nodeType, (char)node->ivalue);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "InitVal") == 0)
    {
        log("%s \n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "InitVals") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "VarDef") == 0)
    {
        log("%s\n", node->nodeType);
        showAst((past)node->evalue, nest + 1);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "VarDefs") == 0)
    {
        log("%s INT \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstInitVal") == 0)
    {
        log("%s \n", node->nodeType);
        showAst(node->left, nest + 1);
    }

    else if (strcmp(node->nodeType, "ConstInitVals") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstExps") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstDef") == 0)
    {
        log("%s \n", node->nodeType);
        showAst((past)node->evalue, nest + 1);
        showAst(node->left, nest + 1);
        showAst(node->right, nest + 1);
    }

    else if (strcmp(node->nodeType, "ConstDefs") == 0)
    {
        log("%s CONST INT\n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "ConstDecl") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }

    else if (strcmp(node->nodeType, "CompUnit") == 0)
    {
        log("%s \n", node->nodeType);
        past t = node->left;
        int i = 1;
        for (; i <= node->ivalue; i++)
        {
            showAst(t, nest + 1);
            t = t->next;
        }
    }
}
