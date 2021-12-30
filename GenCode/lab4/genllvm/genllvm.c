

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "genllvm.h"


char sprintfBuffer[500];
int temVarNum = 0;

void addLLVMCodes(char* codes)
{
	//把生成的指令加入到指令队列，这里为了说明，仅用printf把生成的指令打印出来
	printf("%s", codes);
}


int getTemVarNum()
{
	temVarNum ++;
	return temVarNum;
}



int genPrimaryExpr(past node, char* operand)
{
	int type = -1;
	if(strcmp(node->nodeType, "intValue") == 0)
	{
		type = T_INT;
		if(operand != NULL)
			sprintf(operand, "%d", node->ivalue);
	}
	else if(strcmp(node->nodeType, "expr") == 0)
	{
		//表达式的中间结果用临时变量保存
		//其结果为当前的 temVarNum
		type = genExpr(node);
		if(operand != NULL)
			sprintf(operand, "%%%d", temVarNum);
	}
	else
	{
		printf("ERROR: 发现不支持的运算类型, line %d\n", node->lineno);
	}
	return type;
}

int genExpr(past node)
{
	if(node == NULL)
		return -1;


	int ltype = -1;
	int rtype = -1;

	if( strcmp(node->nodeType, "expr") == 0)
	{
		char loperand[50];
		char roperand[50];
		char oper[5];

		//一元表达式左操作符为空
		if( node->left != NULL)
			ltype = genPrimaryExpr(node->left, loperand);
		rtype = genPrimaryExpr(node->right, roperand);
		if(node->ivalue == 'M')
		{
			//处理一元表达式
			ltype = rtype;
			sprintf(loperand, "0");
		}

		if( ltype == rtype && ltype == T_INT)
		{
			switch(node->ivalue)
			{
			case '+': sprintf(oper, "add nsw"); break;
			case '-': sprintf(oper, "sub nsw"); break;
			case '*': sprintf(oper, "mul nsw"); break;
			case '/': sprintf(oper, "sdiv"); break;
			case '%': sprintf(oper, "srem"); break;
			case 'M': sprintf(oper, "sub nsw"); break;
			}

			sprintf(sprintfBuffer, "  %%%d = %s i32 %s, %s\n",	getTemVarNum(), oper, loperand, roperand);
			addLLVMCodes(sprintfBuffer);

			return T_INT;
		}

	}
	return -1;
}
