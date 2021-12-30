/*
 * main.c
 *
 *  Created on: 2014年10月23日
 *      Author: erqiang
 */

#include<stdio.h>
#include "ast.h"
#include "genllvm.h"

extern int temVarNum;
past astRoot;

void yyerror(char *s)
{
	printf("%s\n", s);
}

int main(int argc, char* argv[])
{
	extern int yyparse(void);
	extern FILE *yyin;


	if (argc < 2)
		yyin = fopen("./expr.txt", "r");
	else
		yyin = fopen(argv[1], "r");

	if (yyparse())
	{
		printf("Error ! Error ! Error !\n");
		return -1;
	}
	fclose(yyin);

	past expr = astRoot->next;
	int count = 1;
	while( expr != NULL)
	{
		printf("\n\n  ==========Expression %d:===========\n", count++);
		showAst(expr, 1);
		printf("\n");
		genExpr(expr);

		expr = expr->next;
		temVarNum = 0;
	}
	return 0;
}
