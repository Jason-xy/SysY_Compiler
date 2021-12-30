%{
#include <stdlib.h>
#include "ast.h"
#include "calc3.tab.h"

extern int lineno;
void yyerror(char *);
%}

%%

[0-9]+  {
			yylval.iValue = atoi(yytext);
			return NUMBER;
		}
		

"+" |
"-" |
"*" |
"/" |
"%" |
"(" |
")" |
";" { return yytext[0]; }


[ \t] ; 	/* skip whitespace */
[\n]	{lineno++;}

. yyerror("invalid character");

%%

int yywrap(void) 
{
	return 1;
}
