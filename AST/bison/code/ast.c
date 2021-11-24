#include "ast.h"

// define the tree node
typedef struct _ast ast;
typedef struct _ast *past;
union astValue
{
    int ivalue;
    char *svalue;
};
struct _ast
{
    union astValue value;
    char *nodeType;
    past left;
    past right;
    past next;
};

past newAstNode(void)
{
    past node = malloc(sizeof(ast));
    if (node == NULL)
    {
        printf("run out of memory.\n");
        exit(0);
    }
    memset(node, 0, sizeof(ast));
    return node;
}

past newAstNode_parameter(char *strVal, char *nodeType, past left, past right, past next)
{
    past node = (past)malloc(sizeof(ast));
    if (node == NULL)
    {
        printf("run out of memory.\n");
        exit(0);
    }
    memset(node, 0, sizeof(ast));
    node->value.svalue = strVal;
    node->nodeType = nodeType;
    node->left = left;
    node->right = right;
    node->next = next;
    return node;
}

past newAstChild(past root, past node)
{
    if (root->left == NULL)
    {
        root->left = node;
    }
    else
        root->left->next = newAstNext(root->left, node);

    return root;
}

past newAstNext(past root, past node)
{
    while (root->next != NULL)
    {
        root = root->next;
    }
    root->next = node;

    return root;
}

past newNum(int value, past next)
{
    past var = newAstNode();
    var->nodeType = "intValue";
    var->value.ivalue = value;
    var->next = next;
    return var;
}

past newType(int type)
{
    past var = newAstNode();
    var->nodeType = "type";
    switch (type)
    {
    case tok_VOID:
        var->value.svalue = "VOID";
        break;
    case tok_INT:
        var->value.svalue = "INT";
        break;
    case tok_CONST:
        var->value.svalue = "CONST";
        break;
    default:
        break;
    }
    var->left = NULL;
    var->right = NULL;
    var->next = NULL;
}

past newIdent(char *strVal, past next)
{
    past var = newAstNode();
    var->nodeType = "varDecl";
    var->value.svalue = strVal;
    var->next = next;
    return var;
}

past newExpr(int oper, past left, past right, past next)
{
    past var = newAstNode();
    switch (oper)
    {
    case tok_LESSEQ:
        var->value.svalue = "<=";
        break;
    case tok_GREATEQ:
        var->value.svalue = ">=";
        break;
    case tok_NOTEQ:
        var->value.svalue = "!=";
        break;
    case tok_EQ:
        var->value.svalue = "==";
        break;
    case tok_AND:
        var->value.svalue = "&&";
        break;
    case tok_OR:
        var->value.svalue = "||";
        break;
    case tok_ADD:
        var->value.svalue = "+";
        break;
    case tok_SUB:
        var->value.svalue = "-";
        break;
    case tok_MUL:
        var->value.svalue = "*";
        break;
    case tok_DIV:
        var->value.svalue = "/";
        break;
    case tok_MODULO:
        var->value.svalue = "%";
        break;
    case tok_LESS:
        var->value.svalue = "<";
        break;
    case tok_GREAT:
        var->value.svalue = ">";
        break;
    case tok_NOT:
        var->value.svalue = "!";
        break;
    default:
        var->value.svalue = "@";
        break;
    }
    var->nodeType = "expr";
    // var->ivalue = oper;
    var->left = left;
    var->right = right;
    var->next = next;
    return var;
}

void showAst(past node, int nest)
{
    if (node == NULL)
        return;
    int i = 0;
    for (i = 0; i < nest; i++)
        printf("  ");
    if (strcmp(node->nodeType, "intValue") == 0)
        printf("%s    .    %d\n", node->nodeType, node->value.ivalue);
    else if (strcmp(node->nodeType, "decl") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "constDecl") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "constDef") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "varDef") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "constInitVal") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "initVal") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "funcDef") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "FuncFParams") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "FuncFParam") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "noexp") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "CompUnit") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "expr") == 0)
    {
        if (strcmp(node->value.svalue, "@") == 0)
            printf("%s    .    '%c'\n", node->nodeType, '@');
        else
            printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    }
    else if (strcmp(node->nodeType, "list") == 0)
        printf("%s    .    %d\n", node->nodeType, node->value.ivalue);
    else if (strcmp(node->nodeType, "varDecl") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "arrayDecl") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "funcDecl") == 0 || strcmp(node->nodeType, "blockDecl") == 0)
        printf("%s    .    \n", node->nodeType);
    else if (strcmp(node->nodeType, "parameter") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "type") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "arrayDecl") == 0)
        printf("%s    .    %s\n", node->nodeType, node->value.svalue);
    else if (strcmp(node->nodeType, "AssignStmt") == 0 || strcmp(node->nodeType, "IfStmt") == 0 || strcmp(node->nodeType, "WhileStmt") == 0 || strcmp(node->nodeType, "BreakStmt") == 0 || strcmp(node->nodeType, "ContinueStmt") == 0 || strcmp(node->nodeType, "ReturnStmt") == 0 || strcmp(node->nodeType, "EmptyStmt") == 0 || strcmp(node->nodeType, "expStmt") == 0)
        printf("%s    .    \n", node->nodeType);

    showAst(node->left, nest + 1);
    showAst(node->right, nest + 1);
    showAst(node->next, nest);
}
