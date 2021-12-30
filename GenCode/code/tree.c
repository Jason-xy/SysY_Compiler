#include "tree.h"

Ast *createNode(int lineno, NodeType type, const char *msg)
{
    Ast *ret = (Ast *)malloc(sizeof(Ast));
    ret->line = lineno;
    ret->nodeType = type;
    bzero(ret->message, MAX_MESSAGE_LEN);
    strcpy(ret->message, msg);
    return ret;
}

void addChild(Ast *root, Ast *node) 
{
    if (root->child == NULL)
        root->child = node;
    else
        addSibling(root->child, node);
}

void addSibling(Ast *root, Ast *node)
{
    while (root->sibling != NULL)
        root = root->sibling;
    root->sibling = node;
}

void printAst(const Ast *root, FILE *fp)
{
    rprintAst(root, 0, fp);
}

void rprintAst(const Ast *root, int height, FILE *fp)
{
    if (root == NULL)
        return;
    for (int i = 0; i < height; i++)
        fprintf(fp, "  ");
    fprintf(fp, "%s\n", root->message);
    rprintAst(root->child, height + 1, fp);
    rprintAst(root->sibling, height, fp);
}

