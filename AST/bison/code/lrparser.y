%{

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);
%}

%union{
    int     iValue;
    char*   eValue;
    past    pAst;
};

/* IF_ELSE reduce/shift conflict */
%expect 1

%token <eValue> IDentifier
%token <iValue>	NUMBER INT VOID CONST IF ELSE WHILE BREAK CONTINUE RETURN CMP ASSIGN
%type  <pAst>    
	Pro CompUnit Decl ConstDecl ConstDef ConstDefs ConstExps ConstInitVal VarDecl VarDef VarDefs
    InitVal InitVals ConstInitVals FuncDef FuncFParams LVal PrimaryExp
    FuncFParam Block BlockItems BlockItem Stmt Exp EqExp 
    Exps Number UnaryExp FuncRParams MulExp AddExp ConstExp Ident Declarator
    SelectionStat ElseStat ExpressionStat IterationStat LValStat ReturnStat BreakStat ContinueStat 
%%

Pro
    : CompUnit                                      { astHead = $1; }
    |                                               { printf("empty\n"); }
    ;

CompUnit
    : CompUnit Decl                                 { $$ = newCompUnit($2, $1); }                                
    | CompUnit FuncDef                              { $$ = newCompUnit($2, $1); }
    | Decl                                          { $$ = newCompUnit($1, NULL); }
    | FuncDef                                       { $$ = newCompUnit($1, NULL); }
    ;

Decl : ConstDecl                                    { $$ = $1; }
    | VarDecl                                       { $$ = $1; }
    ;

ConstDecl
    : CONST INT ConstDefs ';'                       { $$ = $3; }
    ;

ConstDefs
    :ConstDef                                       { $$ = newConstDefs($1,NULL); }
    |ConstDefs ',' ConstDef                         { $$ = newConstDefs($3,$1); }
    ;
ConstDef
    : Ident ASSIGN ConstInitVal                     { $$ = newConstDef($1, NULL, $3); }
    | Ident ConstExps ASSIGN ConstInitVal           { $$ = newConstDef($1, $2, $4); }
    ;

ConstExps
    : '[' ConstExp ']'                              { $$ = newConstExps($2, NULL); }
    | '[' ConstExp ']' ConstExps                    { $$ = newConstExps($2, $4); }
    ;

ConstInitVal
    : ConstExp                                      { $$ = newConstInitVal($1); }
    | '{''}'    									{ $$ = newConstInitVal(NULL); }
    | '{'  ConstInitVals '}'    					{ $$ = newConstInitVal($2); }
    ;

ConstInitVals
    : ConstInitVal                                  { $$ = newConstInitVals($1,NULL); }
    | ConstInitVals ','   ConstInitVal              { $$ = newConstInitVals($3,$1); }
    ;

VarDecl
    : INT VarDefs  ';'                        		{ $$ = $2; }
    ;
VarDefs
    : VarDef                                        { $$ = newVarDefs($1,NULL); }
    | VarDefs ',' VarDef                            { $$ = newVarDefs($3,$1); }
    ;
VarDef
    : Ident                                         { $$ = newVarDef(0, $1, NULL, NULL); }
    | Ident ASSIGN InitVal                        	{ $$ = newVarDef(1, $1, NULL, $3); }
    | Ident ConstExps                               { $$ = newVarDef(2, $1, $2, NULL); }
    | Ident ConstExps ASSIGN InitVal                { $$ = newVarDef(3, $1, $2, $4); }
    ;

InitVal
    : Exp                                           { $$ = newInitVal($1); }
    | '{' '}'        								{ $$ = NULL; }
    | '{' InitVals '}'        				        { $$ = newInitVal($2); }
    ;

InitVals
    : InitVal                                       { $$ = newInitVals($1,NULL);}
    | InitVals ',' InitVal                          { $$ = newInitVals($3,$1);}
    ;

FuncDef
    : INT Declarator Block                    	    { $$ = newFuncDef(0, $2, $3); }
    | VOID Declarator Block                		    { $$ = newFuncDef(1, $2, $3); }
    ;

Declarator
    : Ident '(' FuncFParams ')'                     { $$ = newDeclarator($1, $3); }
    | Ident '(' ')'                                 { $$ = newDeclarator($1, NULL); }
    | Ident                                         { $$ = newDeclarator($1,NULL); }
    ;

FuncFParams
    : FuncFParam                                	{ $$ = newFuncFParams($1, NULL); }
    | FuncFParams ',' FuncFParam                    { $$ = newFuncFParams($3, $1); }
    ;


FuncFParam
    : INT Ident                                     { $$ = newFuncFParam(0, $2, NULL); }
    | INT Ident '[' ']'                 			{ $$ = newFuncFParam(1, $2, NULL); }
    | INT Ident Exps                                { $$ = newFuncFParam(2, $2, $3); }
    | INT Ident '[' ']' Exps             			{ $$ = newFuncFParam(3, $2, $5); }
    ;

Block    
	: '{' BlockItems '}'               				{ $$ = newBlock($2); }
    ;

BlockItems
    : BlockItem                                     { $$ = newBlockItems($1, NULL); }
    | BlockItems BlockItem                          { $$ = newBlockItems($2, $1); }
    ;

BlockItem
    : Decl                                          { $$ = $1; }
    | Stmt                                          { $$ = $1; }
    ;

Stmt
    : LValStat                    	                { $$ = $1; } 
    | Block                                         { $$ = $1; }
    | ExpressionStat                                { $$ = $1; }
    | IterationStat                	                { $$ = $1; }
    | SelectionStat                                 { $$ = $1; }
    | ReturnStat                                    { $$ = $1; }
    | BreakStat                            		    { $$ = $1; }
    | ContinueStat                           	    { $$ = $1; }
    ;

SelectionStat  
    : IF '(' EqExp ')' Stmt ElseStat                { $$ = ifStmt($3, $5, $6); }
    | IF '(' EqExp ')' Stmt                         { $$ = ifStmt($3, $5, NULL); }
    ;
ElseStat
    : ELSE Stmt                                     { $$ = $2; }
    ;
LValStat
    : LVal ASSIGN Exp ';'                    	    { $$ = lvalStmt($1,$3); }
    ;
ExpressionStat
    : ';'                                           { $$ = exprStmt(NULL); }
    | Exp ';'                                       { $$ = exprStmt($1); }
    ;

IterationStat
    : WHILE '(' EqExp ')' Stmt                      { $$ = whileStmt($3, $5); }
    ;

ReturnStat
    : RETURN Exp ';'                        	    { $$ = returnStmt($2); }
    | RETURN ';'                            	    { $$ = returnStmt(NULL); }
    ;
BreakStat
    : BREAK ';'                        	            { $$ = breakStmt(); }
    ;
ContinueStat
    : CONTINUE ';'                        	        { $$ = continueStmt(); }
    ;
Exp
    : AddExp                               		    { $$ = $1; }
    ; 

LVal
    : Ident                                		    { $$ = newLval($1, NULL); }
    | Ident Exps                            	    { $$ = newLval($1, $2); }
    ;

Exps
    : '[' Exp ']'                				    { $$ = newExps($2, NULL); }
    | '[' Exp ']' Exps           				    { $$ = newExps($2, $4); }
    ;

PrimaryExp
    : '(' Exp ')'                     			    { $$ = $2; }
    | LVal                                 		    { $$ = $1; }
    | Number                            		    { $$ = $1; }
    ;

Number
    : NUMBER                            		    { $$ = newNumber($1); }
    ;

UnaryExp
    : PrimaryExp                             	    { $$ = $1; }
    | Ident '(' ')'               				    { $$ = newUnaryExp(-1, $1, NULL); }
    | Ident '(' FuncRParams ')'    				    { $$ = newUnaryExp(-1, $1, $3); }
    | '+' UnaryExp                    			    { $$ = newUnaryExp('+', $2, NULL); }
    | '-' UnaryExp                    			    { $$ = newUnaryExp('-', $2, NULL); }
    | '!' UnaryExp                    			    { $$ = newUnaryExp('!', $2, NULL); }
    ;


FuncRParams
    : Exp                            			    { $$ = newFuncRParams($1, NULL); }
    | FuncRParams ',' Exp                      	    { $$ = newFuncRParams($3, $1); }
    ;


MulExp
    : UnaryExp                     				    { $$ = $1; } 
    | MulExp '*' UnaryExp        				    { $$ = newExpr('*', $1, $3); } 
    | MulExp '/' UnaryExp        				    { $$ = newExpr('/', $1, $3); } 
    | MulExp '%' UnaryExp        				    { $$ = newExpr('%', $1, $3); } 
    ;

AddExp
    : MulExp                         			    { $$ = $1; } 
    | MulExp '+' AddExp        					    { $$ = newExpr('+', $1, $3); } 
    | MulExp '-' AddExp         				    { $$ = newExpr('-', $1, $3); } 
    ;

EqExp
    : AddExp                         			    { $$ = $1; } 
    | EqExp CMP AddExp            				    { $$ = newExpr($2, $1, $3); }  
    ;

ConstExp
    : AddExp                        			    { $$ = $1; } 
    ;

Ident
    : IDentifier                   				    { $$ = newString($1); }
    ;

%%