/*
 * ast.h
 *
 *  Created on: 2014年10月23日
 *      Author: erqiang
 */


typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	int ivalue;
	char* nodeType;
	past left;
	past right;
};

past newNum(int value);
past newExpr(int oper, past left,past right);
void showAst(past node, int nest);
