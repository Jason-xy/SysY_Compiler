/*
 * main.c
 *
 *  Created on: 2014年10月23日
 *      Author: erqiang
 */


#include<stdio.h>

void yyerror(char *s)
{
	printf("%s\n", s);
}

int main(void)
{
    yyparse();
    return 0;
}
