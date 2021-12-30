%{

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
extern past astRoot;

%}

%union{
	int			iValue;
	past		pAst;
};


%token <iValue> NUMBER
%type  <pAst>	program expr factor term

%%

program : program expr ';'		{ $$ = newList($1, $2); }
		| expr ';'				{ $$ = newList(NULL, $1); astRoot = $$;}
		;

expr: factor			  
	| expr '+' factor     {$$ = newExpr('+', $1, $3);}
	| expr '-' factor     {$$ = newExpr('-', $1, $3);}
	;
	
factor: term
	| factor '*' term    {$$ = newExpr('*', $1, $3);} 
	| factor '/' term    {$$ = newExpr('/', $1, $3);}
	| factor '%' term    {$$ = newExpr('%', $1, $3);}
	;
	
term: NUMBER            {$$ = newNum($1);}
	| '-' term          {$$ = newExpr('M', NULL, $2); }
	| '(' expr ')'		{$$ = $2; }
	;

%%

