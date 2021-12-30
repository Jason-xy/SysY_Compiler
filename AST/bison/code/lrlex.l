%{
#include <stdlib.h>
#include "ast.h"
#include "y.tab.h"


void yyerror(char const* msg, ...);
int lineno = 1;



%}

DEX [1-9][0-9]*|[0]
HEX [0][Xx]([1-9][0-9a-fA-F]*|[0])
OCT [0][0-7]*
ID              [a-zA-Z_][a-zA-Z_0-9]*

%%

"/*"([^\*]|(\*)+[^/])*"*/"				{  }
"//".*				{  }

int					{ yylval.iValue = tok_INT; return INT;}
const				{ yylval.iValue = tok_CONST; return CONST;}
void				{ yylval.iValue = tok_VOID; return VOID;}
if					{ return IF;}
else				{ return ELSE;}
while				{ return WHILE;}
break				{ return BREAK;}
continue			{ return CONTINUE;}
return				{ return RETURN;}

"+"|"-"|"*"|"/"|"%"|"&"|""|"!"      { return yytext[0]; }
"{"|"}"|"["|"]"         			{ return yytext[0]; }
","|";"                 			{ return yytext[0]; }
"("|")"                 			{ return yytext[0]; }

"<"					{ yylval.iValue = tok_LESS; return CMP;}
">"					{ yylval.iValue = tok_GREAT; return CMP;}
"<="				{ yylval.iValue = tok_LESSEQ; return CMP;}
">="				{ yylval.iValue = tok_GREATEQ; return CMP;}
"=="				{ yylval.iValue = tok_EQ; return CMP;}
"!="				{ yylval.iValue = tok_NOTEQ; return CMP;}
"&&"				{ yylval.iValue = tok_AND; return CMP;}
"||"				{ yylval.iValue = tok_OR; return CMP;}

"="					{ yylval.iValue = tok_ASSIGN; return ASSIGN;}

\n					{ ++lineno; }
[ \t]				{  }
{DEX} 				{ yylval.iValue = atoi(yytext); return NUMBER;}
{HEX} 				{ yylval.iValue = strtol(yytext, NULL, 16); return NUMBER;}
{OCT} 				{ yylval.iValue = strtol(yytext, NULL, 8); return NUMBER;}
{ID}				{ yylval.eValue = strdup(yytext); return IDentifier;}

.                   { yyerror("line:%d unknown character %s", lineno, yytext); }
%%

int yywrap(void)
{
	return 1;
}



