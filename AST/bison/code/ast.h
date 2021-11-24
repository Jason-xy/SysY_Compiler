#ifndef __AST_H__
#define __AST_H__

#include "tok.h"
#define NULL 0
void showAst(past node, int nest);
past newExpr(int oper, past left, past right, past next);
past newIdent(char *strVal, past next);
past newType(int type);
past newNum(int value, past next);
past newAstNode_parameter(char *strVal, char *nodeType, past left, past right, past next);
past newAstNode(void);
past newAstChild(past root, past node);
past newAstNext(past root, past node);

#endif // __AST_H__
