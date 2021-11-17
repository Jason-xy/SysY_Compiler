%{
#include <stdio.h>
#include "tok.h"
char* yyID;
int yyNUM;
%}

WHITE [\t\n ]
DIGIT [0-9]
OINTEGER [1-9]{DIGIT}*
INTEGER 0|{OINTEGER}

LETTER [a-zA-Z]
ID ({LETTER}|_)({LETTER}|_|{DIGIT})*


%%
{WHITE}+      ;
\/\*(\s|.)*?\*\/ { /* ignore note */ }
\/\/.* { /* ignore note */ }
{INTEGER}     {yyNUM = atoi(yytext); return tok_INTEGER;}
(int)         {return tok_INT;}
(void)        {return tok_RETURN;}
(const)       {return tok_CONST;}
(if)          {return tok_IF;}
(else)        {return tok_ELSE;}
(while)       {return tok_WHILE;}
(break)       {return tok_BREAK;}
(continue)    {return tok_CONTINUE;}
(return)      {return tok_RETURN;}
{ID}          {yyID = yytext; return tok_ID;}
"+"           {return tok_ADD;}
"-"           {return tok_SUB;}
"*"           {return tok_MUL;}
"/"           {return tok_DIV;}
"%"           {return tok_MODULO;}
"<"           {return tok_LESS;}
"<="          {return tok_LESSEQ;}
">"           {return tok_GREAT;}
">="          {return tok_GREATEQ;}
"!="          {return tok_NOTEQ;}
"=="          {return tok_EQ;}
"!"           {return tok_NOT;}
"&&"          {return tok_AND;}
"||"          {return tok_OR;}
"="           {return tok_ASSIGN;}
"("           {return tok_LPAR;}
")"           {return tok_RPAR;}
"{"           {return tok_LBRACKET;}
"}"           {return tok_RBRACKET;}
"["           {return tok_LSQUARE;}
"]"           {return tok_RSQUARE;}
","           {return tok_COMMA;}
";"           {return tok_SEMICOLON;}

.          	  { printf("Mystery character %c\n", *yytext); }
%%

int main(int arg,char **argv) {
    int tok;
	if(arg>1){
        if(!(yyin=fopen(argv[1],"r"))){
            perror(argv[1]);
            return 1;
        }
    }
    
    while(tok = yylex()){
        if(tok == tok_ID)
            printf("%d %s\n", tok_ID,yyID);
        else if(tok == tok_INTEGER) 
            printf("%d %d\n", tok_INTEGER,yyNUM);
        else 
            printf("%d\n",tok);
    }
}
