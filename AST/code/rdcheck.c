/*
 ============================================================================
@Author      : JasonHsu
@Date        : 2021-11-16
@Name        : rdcheck.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tok.h"

extern int yylex();
extern void yyputback(char* yytext);
extern FILE* yyin;
extern char* yytext;
extern char* yyID;
extern int yyNUM;

//每一个非终结符都对应一个函数
int CompUnit(void);
int Decl(void);
int ConstDecl(void);
int BType(void);
int ConstDef(void);
int ConstInitVal(void);
int VarDecl(void);
int VarDef(void);
int InitVal(void);
int FuncDef(void);
int FuncType(void);
int FuncFParams(void);
int FuncFParam(void);
int Block(void);
int BlockItem(void);
int Stmt(void);
int Exp(void);
int Cond(void);
int LVal (void);
int PrimaryExp(void);
int Number(void);
int UnaryExp(void);
int UnaryOp(void);
int FuncRParams(void);
int MulExp(void);
int AddExp(void);
int RelExp(void);
int EqExp(void);
int LAndExp(void);
int LOrExp(void);
int ConstExp(void);


int tok;

void advance(void){
	tok = yylex();
	printf("tok: %d\t%s\n", tok, yytext);
}

void error(void){
	printf("The match failed, please check\n");
	exit(0);
}

int main(int argc, char **argv)
{
	// if(argc != 2 )
	// {
	// 	printf("input file is needed.\n");
	// 	return 0;
	// }
	// FILE* yyin = fopen(argv[1], "r");
	setbuf(stdout,NULL);
	yyin = fopen("/home/jason/github/SysY_Compiler/test_cases/10_break.c", "r");
	advance();
	int r = CompUnit();
	printf("result: %d\n", r);
	// past rr = astExpr();
	// showAst(rr, 0);

	return 0;
}

// CompUnit
//		：Decl 
//		| FuncDef
//		| CompUnit Decl
//		| CompUnit FuncDef
int CompUnit(void){
	if(tok == tok_CONST || tok == tok_VOID || tok == tok_INT){
		if(tok == tok_CONST){
			if(!Decl());
			else return 1;
		}
		else if(tok == tok_VOID){
			if(!FuncDef());
			else return 1;
		}
		else{ 
			char* s0 = strdup(yytext);
			advance();
			if(tok == tok_ID){
				char* s1 = strdup(yytext);
				advance();
				if(tok == tok_LPAR){
					yyputback(yytext);
					yyputback(s1);
					yyputback(s0);
					advance();
					if(!FuncDef());
					else return 1;
				}
				else{
					yyputback(yytext);
					yyputback(s1);
					yyputback(s0);
					advance();
					if(!Decl());
					else return 1;
				}
			}
			else return 1;
		}
	}
	else return 1;

	while(1){
		if (tok == '\n' || tok == EOF || tok == 0) {
			return 0;
		}
		if(tok == tok_CONST || tok == tok_VOID || tok == tok_INT){
			if(tok == tok_CONST){
				if(!Decl());
				else return 1;
			}
			else if(tok == tok_VOID){
				if(!FuncDef());
				else return 1;
			}
			else{ 
				char* s0 = strdup(yytext);
				advance();
				if(tok == tok_ID){
					char* s1 = strdup(yytext);
					advance();
					if(tok == tok_LPAR){
						yyputback(yytext);
						yyputback(s1);
						yyputback(s0);
						advance();
						if(!FuncDef());
						else return 1;
					}
					else{
						yyputback(yytext);
						yyputback(s1);
						yyputback(s0);
						advance();
						if(!Decl());
						else return 1;
					}
				}
				else return 1;
			}
		}
		else return 1;
	}

	return 0;
}

// Decl
//		: ConstDecl
//		| VarDecl
int Decl(void){
	if(tok == tok_CONST){
		if(!ConstDecl());
		else return 1;
	}
	else if(!VarDecl());
	else return 1;

	return 0;
}

//ConstDecl
//		: 'const' BType ConstDef { ',' ConstDef } ';'
int ConstDecl(void){
	// 'const'
	if(tok == tok_CONST){
		advance();
		// BType
		if(!BType());
		else { return 1;}

		// ConstDef
		if(!ConstDef());
		else return 1;

		// { ',' ConstDef }
		while(tok == tok_COMMA){
			advance();
			if(!ConstDef());
			else { return 1;}
		}
		// ';'
		if(tok == tok_SEMICOLON)
			advance();
		else return 1;
	}
	else return 1;
	return 0;
}

// BType
//		: 'int'
int BType(void){
	if(tok == tok_INT){
		advance();
	}
	else return 1;

	return 0;
}

// ConstDef
//		: Ident { '[' ConstExp ']' } '=' ConstInitVal
int ConstDef(void){
	// Ident
	if(tok == tok_ID){
		advance();
		// { '[' ConstExp ']' }
		while(tok == tok_LSQUARE){
			advance();
			// ConstExp
			if(!ConstExp());
			else { return 1;}
			// ']'
			if(tok == tok_RSQUARE){
				advance();
			}
			else { return 1;}
		}
		// '='
		if(tok == tok_ASSIGN){
			advance();
		}
		else { return 1;}
		// ConstInitVal
		if(!ConstInitVal());
		else return 1;
	}
	else return 1;

	return 0;
}

// ConstInitVal
//		: ConstExp
//		| '{' [ ConstInitVal { ',' ConstInitVal } ] '}'
int ConstInitVal(void){
	// ConstExp
	if(tok == tok_LBRACKET){
		advance();
		// [ ConstInitVal { ',' ConstInitVal } ]
		if(!ConstInitVal()){
			while(tok == tok_COMMA){
				advance();
				if(!ConstInitVal()){
					// '}'
					if(tok == tok_RBRACKET){
						advance();
						return 0;
					}
					else ;
				}
				else return 1;
			}
		}
		else return 1;
	}
	else if(!ConstExp());
	else return 1;

	return 0;
}

// VarDecl
//		: BType VarDef { ',' VarDef } ';'
int VarDecl(void){
	if(!BType()){
		if(!VarDef()){
			while(tok == tok_COMMA){
				advance();
				if(!VarDef());
				else { return 1;}
			}
			if(tok == tok_SEMICOLON){
				advance();
			}
			else { return 1;}
		}
		else return 1;
	}
	else return 1;

	return 0;
}

// VarDef
//		: Ident { '[' ConstExp ']' }
//		| Ident { '[' ConstExp ']' } '=' InitVal
int VarDef(void){
	if(tok == tok_ID){
		advance();
		// { '[' ConstExp ']' }
		while(tok == tok_LSQUARE){
			advance();
			if(!ConstExp()){
				if(tok == tok_RSQUARE){
					advance();

				}
				else {  return 1;}
			}
			else { return 1;}
		}
		// '=' InitVal
		if(tok == tok_ASSIGN){
			advance();
			if(!InitVal());
			else return 1;
		}
					else ;
	}
	else return 1;

	return 0;
}

// InitVal
//		: Exp 
//		| '{' [ InitVal { ',' InitVal } ] '}'
int InitVal(void){
	if(tok == tok_LBRACKET){
		advance();
		// [ InitVal { ',' InitVal } ]
		if(!InitVal()){
			// { ',' InitVal }
			while(tok == tok_COMMA){
				advance();
				if(!InitVal());
				else return 1;
			}
		}
		else ;

		if(tok == tok_RBRACKET){
			advance();
		}
		else return 1;
	}
	else if(!Exp());
	else return 1;

	return 0;
}

// FuncDef
//		: FuncType Ident '(' [FuncFParams] ')' Block
int FuncDef(void){
	if(!FuncType()){
		if(tok == tok_ID){
			advance();
			if(tok == tok_LPAR){
				advance();
				if(!FuncFParams());
				else ;
				if(tok == tok_RPAR){
					advance();
					if(!Block());
					else {   return 1;}
				}
				else {  return 1;}
			}
			else { return 1;}
		}
		else return 1;
	}
	else return 1;

	return 0;
}

// FuncType
//		: 'void' 
//		| 'int'
int FuncType(void){
	if(tok == tok_VOID){
		advance();
	}
	else if(tok == tok_INT){
		advance();
	}
	else return 1;

	return 0;
}

// FuncFParams
//		: FuncFParam { ',' FuncFParam }
int FuncFParams(void){
	if(!FuncFParam()){
		while(tok == tok_COMMA){
			advance();
			if(!FuncFParam());
			else { return 1;}
		}
	}
	else return 1;

	return 0;
}

// FuncFParam
//		: BType Ident ['[' ']' { '[' Exp ']' }]
int FuncFParam(void){
	if(!BType()){
		if(tok == tok_ID){
			advance();
		}
		else return 1;

		if(tok == tok_LSQUARE){
			advance();
			if(tok == tok_RSQUARE){
				advance();
			}
			else { return 1;}

			while(tok == tok_LSQUARE){
				advance();
				if(!Exp());
				else { return 1;}

				if(tok == tok_RSQUARE){
					advance();
				}
				else { return 1;}
			}
		}
		else ;
	}
	else return 1;

	return 0;
}

// Block
//		: '{' { BlockItem } '}'
int Block(void){
	if(tok == tok_LBRACKET){
		advance();
		while(!BlockItem());
		if(tok == tok_RBRACKET){
			advance();
		}
		else { return 1;}
	}
	else return 1;

	return 0;
}

// BlockItem
//		: Decl 
//		| Stmt
int BlockItem(void){
	if(!Decl());
	else if(!Stmt());
	else return 1;
}

// Stmt
//		: LVal '=' Exp ';' 
//		| [Exp] ';' 
//		| Block
//		| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
//		| 'while' '(' Cond ')' Stmt
//		| 'break' ';' 
//		| 'continue' ';'
//		| 'return' [Exp] ';'
int Stmt(void){
	if(tok == tok_IF){
		advance();
		if(tok == tok_LPAR){
			advance();
			if(!Cond());
			else return 1;
			if(tok == tok_RPAR){
				advance();
				if(!Stmt()){
					if(tok == tok_ELSE){
						advance();
						if(!Stmt());
						else return 1;
					}
					else ;
				}
				else return 1;
			}
			else return 1;
		}
		else return 1;
	}
	else if(tok == tok_WHILE){
		advance();
		if(tok == tok_LPAR){
			advance();
			if(!Cond());
			else return 1;
			if(tok == tok_RPAR){
				advance();
				if(!Stmt());
				else return 1;
			}
			else return 1;
		}
		else return 1;
	}
	else if(tok == tok_BREAK){
		advance();
		if(tok == tok_SEMICOLON){
			advance();
		}
		else return 1;
	}
	else if(tok == tok_CONTINUE){
		advance();
		if(tok == tok_SEMICOLON){
			advance();
		}
		else return 1;
	}
	else if(tok == tok_RETURN){
		advance();
		if(!Exp());
		else ;
		if(tok == tok_SEMICOLON){
			advance();
		}
		else return 1;
	}
	else if(tok == tok_SEMICOLON){
		return 0;
	}
	else if(tok == tok_ID){
		if(!LVal()){
			if(tok == tok_ASSIGN){
				advance();
				if(!Exp()){
					if(tok == tok_SEMICOLON)
						advance();
				}
				else return 1;
			}
			else return 1;
		}
		else return 1;
	}
	else if(tok == tok_LBRACKET){
		if(!Block());
		else return 1;
	}
	else if(!Exp()){
		if(tok == tok_SEMICOLON){
			advance();
		}
		else return 1;
	}
	else return 1;

	return 0;
}

// Exp
//		: AddExp 
int Exp(void){
	
	if(!AddExp());
	else return 1;
	
	return 0;
}

// Cond
//		: LOrExp
int Cond(void){
	if(!LOrExp());
	else return 1;

	return 0;
}

// LVal
//		: Ident {'[' Exp ']'}
int LVal (void){
	if(tok == tok_ID){
		advance();
		while(tok == tok_LSQUARE){
			advance();
			if(!Exp());
			else return 1;
			if(tok == tok_RSQUARE){
				advance();
			}
			else { return 1;}
		}
	}
	else return 1;

	return 0;
}

// PrimaryExp
//		：'(' Exp ')' 
//		| LVal 
//		| Number
int PrimaryExp(void){
	if(tok == tok_LPAR){
		advance();
		if(!Exp());
		//modified
		else ;

		if(tok == tok_RPAR){
			advance();
		}
		else return 1;
	}
	else if(tok == tok_INTEGER){
		if(!Number());
		else return 1;
	}
	else if(!LVal());
	else return 1;

	return 0;
}

// Number
//		：IntConst
int Number(void){
	if(tok == tok_INTEGER){
		advance();
	}
	else return 1;

	return 0;
}

// UnaryExp
//		：PrimaryExp 
//		| Ident '(' [FuncRParams] ')'
//		| UnaryOp UnaryExp
int UnaryExp(void){

	if(tok == tok_ADD || tok == tok_SUB || tok == tok_NOT){
		advance();
		while(tok == tok_ADD || tok == tok_SUB || tok == tok_NOT){
			advance();
			if(!UnaryOp()){
				if(!UnaryExp);
				return 1;
			}
			return 1;
		}
	}
	else if(!PrimaryExp());
	else if(tok == tok_ID){
		char *s0 = strdup(yytext);
		advance();
		if(tok == tok_LPAR){
			advance();
			if(!FuncRParams());
			else ;
			if(tok == tok_RPAR){
				advance();
			}
			else return 1;
		}
		else return 1;
	}
	else return 1;

	return 0;
}

// UnaryOp
//		：'+' 
//		| '−' 
//		| '!' 
int UnaryOp(void){
	if(tok == tok_ADD || tok == tok_SUB || tok == tok_NOT){
		advance();
	}
	else return 1;

	return 0;
}

// FuncRParams
//		: Exp { ',' Exp }
int FuncRParams(void){
	if(!Exp()){
		while(tok == tok_COMMA){
			advance();
			if(!Exp());
			else { return 1;}
		}
	}
	else return 1;

	return 0;
}

// MulExp
//		: UnaryExp 
//		| MulExp ('*' | '/' | '%') UnaryExp
int MulExp(void){

	if(!UnaryExp());
	else return 1;

	while(tok == tok_MUL || tok == tok_DIV || tok == tok_MODULO){
		advance();
		if(!UnaryExp());
		else return 1;
	}

	return 0;
}

// AddExp
//		: MulExp 
//		| AddExp ('+' | '−') MulExp
int AddExp(void){

	if(!MulExp());
	else return 1;

	while(tok == tok_ADD || tok == tok_SUB){
		advance();
		if(!MulExp());
		else return 1;
	}

	return 0;
}

// RelExp
//		: AddExp 
//		| RelExp ('<' | '>' | '<=' | '>=') AddExp
int RelExp(void){

	if(!AddExp());
	else return 1;

	while(tok == tok_LESS || tok == tok_GREAT || tok == tok_LESSEQ || tok == tok_GREATEQ){
		advance();
		if(!AddExp());
		else return 1;
	}

	return 0;
}

// EqExp
//		: RelExp 
//		| EqExp ('==' | '!=') RelExp
int EqExp(void){

	if(!RelExp());
	else return 1;

	while(tok == tok_EQ || tok == tok_NOTEQ){
		advance();
		if(!RelExp());
		else return 1;
	}
	
	return 0;
}

// LAndExp
//		: EqExp 
//		| LAndExp '&&' EqExp
int LAndExp(void){

	if(!EqExp());
	else return 1;

	while(tok == tok_AND){
		advance();
		if(!EqExp());
		else return 1;
	}

	return 0;
}

// LOrExp
//		: LAndExp 
//		| LOrExp '||' LAndExp
int LOrExp(void){

	if(!LAndExp());
	else return 1;

	while(tok == tok_OR){
		advance();
		if(!LAndExp());
		else return 1;
	}

	return 0;
}

// ConstExp
//		: AddExp
int ConstExp(void){
	if(!AddExp());
	else return 1;

	return 0;
}


