/*
 ============================================================================
 Name        : rdparser.c
 Author      : Jason_xy
 Version     : 1.0
 Date        : 2021-10-26
 Github      : https://github.com/Jason-xy/SysY_Compiler
 Description : Recursive descent parser
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tok Type*/
enum yytokentype {
	tok_ID=256,		 // 标识符
	tok_INTEGER,	 // 整数
	tok_INT,		 // int
	tok_VOID,		 // void
	tok_CONST,		 // const
	tok_IF,			 // if
	tok_ELSE,		 // else
	tok_WHILE,		 // while
	tok_BREAK,		 // break
	tok_CONTINUE,	 // continue
	tok_RETURN,		 // return
	tok_ADD,		 // +
	tok_SUB,		 // -
	tok_MUL,		 // *
	tok_DIV,		 // /
	tok_MODULO,		 // %
	tok_LESS,		 // <
	tok_LESSEQ,		 // <=
	tok_GREAT,		 // >
	tok_GREATEQ,	 // >=
	tok_NOTEQ,		 // !=
	tok_EQ,		 	 // ==
	tok_NOT,		 // !
	tok_AND, 		 // &&
	tok_OR,			 // ||
	tok_ASSIGN,		 // =
	tok_LPAR,		 // (
	tok_RPAR,		 // )
	tok_LBRACKET,	 // {
	tok_RBRACKET,	 // }
	tok_LSQUARE,	 // [
	tok_RSQUARE,	 // ]
	tok_COMMA,		 // ,
	tok_SEMICOLON	 // ;
}; 


int main(int argc, char **argv)
{
	while(1)
	{
		printf("input expression, 'q' to exit>");
		advance();
		int r = expr();
		printf("result: %d\n", r);
	}
	return 0;
}

