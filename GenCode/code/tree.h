#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum _NodeType
{
    NT_ROOT,

    NT_CONSTANT, // Branches:0
    NT_VAR,      // Branches:0
    NT_TYPE,     // Branches:0

    NT_OP_POS,    // +(单目)      // Branches:1   0:Operand
    NT_OP_NEG,    // -(单目)      // Branches:1   0:Operand
    NT_OP_NOT,    // !      // Branches:1   0:Operand
    NT_OP_AND,    // &&     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_OR,     // ||     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_ADD,    // +      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_SUB,    // -      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_MUL,    // *      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_DIV,    // /      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_MOD,    // %      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_L,      // <      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_LE,     // <=     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_G,      // >      // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_GE,     // >=     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_E,      // ==     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_NE,     // !=     // Branches:2   0:LeftOperand 1:RightOperand
    NT_OP_INDEX,  // []     // Branches:2   0:Ident 1:Index
    NT_OP_ASSIGN, // =      // Branches:2   0:LVal 1:Exp

    NT_FUNCCALL, // Branches:2   0:Ident 1:VarList

    NT_STMT, // Branches:2   0:Stmt 1:NextStmt

    NT_STMT_BLOCK,     // Branches:1   0:BodyFirstStmt
    NT_STMT_VARDECL,   // Branches:2   0:Type 1:VarDeclList
    NT_STMT_CONSTDECL, // Branches:2   0:Type 1:VarDeclList
    NT_STMT_FUNCDEF,   // Branches:4   0:Type 1:Ident 2:Params 3:Body
    NT_STMT_IFELSE,    // Branches:3   0:Cond 1:IfBody 2:ElseBody
    NT_STMT_WHILE,     // Branches:2   0:Cond 1:Body
    NT_STMT_RETURN,    // Branches:1   0:ReturnVal
    NT_STMT_CONTINUE,  // Branches:0
    NT_STMT_BREAK,     // Branches:0
    NT_STMT_EXPR,      // Branches:1   0:Operation

    NT_PARAM,      // Branches:3   0:Type 1:Ident 2:NextParam
    NT_VARLIST,    // Branches:2   0:Exp 1:NextVar
    NT_VARDECLLIST // Branches:3   0:Ident 1:InitVal 2:NextVar
} NodeType;

#define MAX_MESSAGE_LEN 40

struct _ast
{
    int line;
    int value;
    NodeType nodeType;
    struct _ast *child;
    struct _ast *sibling;
    char message[MAX_MESSAGE_LEN];
};

typedef struct _ast Ast;

Ast *createNode(int lineno, NodeType type, const char *msg);

void addChild(Ast *root, Ast *node);

void addSibling(Ast *root, Ast *node);

void printAst(const Ast *root, FILE *fp);

void rprintAst(const Ast *root, int height, FILE *fp);

#endif