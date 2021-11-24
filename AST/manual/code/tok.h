//
// Created by erqiang on 25/10/21.
//

#ifndef LEXENUM_TOK_H
#define LEXENUM_TOK_H
enum Token_T{
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

/*
词法分析输出示例：

int main () {int a = 100; return 0;}

258
256 main
282
283
284
258
256 a
281
257 100
289
266
257 0
289
285
 */
#endif //LEXENUM_TOK_H
