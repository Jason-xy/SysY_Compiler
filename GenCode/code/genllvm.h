#ifndef GENLLVM_H
#define GENLLVM_H
#include <stdio.h>
#include "tree.h"

int getVarNum();
void printLine();
void printLabel(int num);
void printEmptyLine();

void genRoot(Ast *root);
void genGlobalVarDecl(Ast *root);
void genGlobalConstDecl(Ast *root);
void genFuncDef(Ast *root);
void genBlock(Ast *root);
int genExpr(Ast *root);
int genFuncCall(Ast *root);
void genIfElse(Ast *root);
void genWhile(Ast *root);


#endif