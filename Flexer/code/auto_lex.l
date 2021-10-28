/* recognize tokens for the calculator and print them out */
%{
#include <string.h> 
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
int yylval;
char* yylstr = NULL;
%}

%%
[_a-zA-Z][_ a-zA-Z0-9]* { yylstr = yytext; return tok_ID; } /*标识符*/
[0-9]+ { yylval = atoi(yytext); return tok_INTEGER; }
"\bint\b" { return tok_INT; }
"\bvoid\b" { return tok_VOID; }
"\bconst\b" { return tok_CONST; }
"\bif\b" { return tok_IF; }
"\belse\b" { return tok_ELSE; }
"\bwhile\b" { return tok_WHILE; }
"\bbreak\b" { return tok_BREAK; }
"\bcontinue\b" { return tok_CONTINUE; }
"\breturn\b" { return tok_RETURN; }
"+" { return tok_ADD; }
"-" { return tok_SUB; }
"*" { return tok_MUL; }
"/" { return tok_DIV; }
"%" { return tok_MODULO; }
"<" { return tok_LESS; }
"<=" { return tok_LESSEQ; }
">" { return tok_GREAT; }
">=" { return tok_GREATEQ; }
"!=" { return tok_NOTEQ; }
"==" { return tok_EQ; }
"!" { return tok_NOT; }
"&&" { return tok_AND; }
"||" { return tok_OR; }
"=" { return tok_ASSIGN; }
"(" { return tok_LPAR; }
")" { return tok_RPAR; }
"{" { return tok_LBRACKET; }
"}" { return tok_RBRACKET; }
"[" { return tok_LSQUARE; }
"]" { return tok_RSQUARE; }
"," { return tok_COMMA; }
";" { return tok_SEMICOLON; }
\/\*(\s|.)*?\*\/ { /* ignore note */}
[ \t] { /* ignore whitespace */ }
. 	{ printf("Mystery character %c\n", *yytext); }
%%

int main(int argc, char **argv)
{
	int tok;
	while(tok = yylex()) 
	{
		if(tok == tok_ID) 
			printf("%d %s\n", tok_ID, yylstr);
		else if(tok == tok_INTEGER) 
			printf("%d %d\n", tok_INT, yylval);
		else 
			printf("%d\n", tok);
	}
    return 0;
}