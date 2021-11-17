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
#include <tok.h>

extern int yylex();
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
	printf("tok: %s\n", yytext);
}

void error(void){
	printf("The match failed, please check\n");
	exit(0);
}
// CompUnit
//		：Decl 
//		| FuncDef
//		| CompUnit Decl
//		| CompUnit FuncDef
int CompUnit(void){
    if (tok == 'q') {
		exit(0);
	}
    if(!Decl())
	else if(!FuncDef())
	else error();
    while (1) {
		if (tok == '\n' || tok == EOF || tok == EOL) {
			return 0;
		}
		if(!Decl())
		else if(!FuncDef())
		else error();
	}
	return 0;
}

// Decl
//		: ConstDecl
//		| VarDecl
int Decl(void){
    if(!ConstDecl())
	else if(!VarDecl())
	else error();
    return 0;
}

//ConstDecl
//		: 'const' BType ConstDef { ',' ConstDef } ';'
int ConstDecl(void){
	// 'const'
	if(tok == tok_CONST){
		advance();
		// BType
		if(!BType())
		else error();

		// ConstDef
		if(!ConstDef())
		else error();

		// { ',' ConstDef }
		while(tok == tok_COMMA){
			advance();
			if(!ConstDef())
			else error();
		}
		// ';'
		if(tok == tok_SEMICOLON)
			advance();
		else error();
	}
	else error();
	return 0;
}

// BType
//		: 'int'
int BType(void){
	if(tok == tok_INT){
		advance();
	}
	else error();

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
			if(!ConstExp())
			else error();
			// ']'
			if(tok == tok_RSQUARE){
				advance();
			}
			else error();
		}
		// '='
		if(tok == tok_ASSIGN){
			advance();
		}
		else error();
		// ConstInitVal
		if(!ConstInitVal())
		else error();
	}
	else error();

	return 0;
}

// ConstInitVal
//		: ConstExp
//		| '{' [ ConstInitVal { ',' ConstInitVal } ] '}'
int ConstInitVal(void){
	// ConstExp
	if(!ConstExp())
	else if(tok == tok_LBRACKET){
		advance();
		// [ ConstInitVal { ',' ConstInitVal } ]
		if(!ConstInitVal()){
			while(tok == tok_COMMA){
				advance();
				if(!ConstInitVal())
				else error();
			}
		}
		else ;

		// '}'
		if(tok == tok_RBRACKET){
			advance();
		}
		else error();
	}
	else error();

	return 0;
}

// VarDecl
//		: BType VarDef { ',' VarDef } ';'
int VarDecl(void){
	if(!BType()){
		if(!VarDef()){
			while(tok == tok_COMMA){
				advance();
				if(!VarDef())
				else error();
			}
			if(tok == tok_SEMICOLON){
				advance();
			}
			else error();
		}
		else error();
	}
	else error();

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
				else error();
			}
			else error();
		}
		// '=' InitVal
		if(tok == tok_ASSIGN){
			advance();
			if(!InitVal())
			else error();
		}
		else ;
	}
	else error();

	return 0;
}

// InitVal
//		: Exp 
//		| '{' [ InitVal { ',' InitVal } ] '}'
int InitVal(void){
	if(!Exp())
	else if(tok == tok_LBRACKET){
		advance();
		// [ InitVal { ',' InitVal } ]
		if(!InitVal()){
			// { ',' InitVal }
			while(tok == tok_COMMA){
				advance();
				if(!InitVal())
				else error();
			}
		}
		else ;

		if(tok == tok_RBRACKET){
			advance();
		}
		else error();
	}
	else error();

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
				if(!FuncFParams())
				else ;
				if(tok == tok_RPAR){
					advance();
					if(!Block())
					else error();
				}
				else error();
			}
			else error();
		}
		else error();
	}
	else error();

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
	else error();

	return 0;
}

// FuncFParams
//		: FuncFParam { ',' FuncFParam }
int FuncFParams(void){
	if(!FuncFParam()){
		while(tok == tok_COMMA){
			advance();
			if(!FuncFParam())
			else error();
		}
	}
	else error();

	return 0;
}

// FuncFParam
//		: BType Ident ['[' ']' { '[' Exp ']' }]
int FuncFParam(void){
	if(!BType()){
		if(tok == tok_ID){
			advance();
		}
		else error();

		if(tok == tok_LSQUARE){
			advance();
			if(tok == tok_RSQUARE){
				advance();
			}
			else error();

			while(tok == tok_LSQUARE){
				advance();
				if(!Exp())
				else error();

				if(tok == tok_RSQUARE){
					advance();
				}
				else error();
			}
		}
		else ;
	}
	else error();

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
		else error();
	}
	else error();

	return 0;
}

// BlockItem
//		: Decl 
//		| Stmt
int BlockItem(void){
	if(!Decl())
	else if(!Stmt())
	else error();
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
	if(!LVal()){
		if(tok == tok_ASSIGN){
			advance();
			if(!Exp())
			else error();
			if(tok == tok_SEMICOLON){
				advance();
			}
			else error();
		}
		else error();
	}
	else if(!Exp()){
		if(tok == tok_SEMICOLON){
			advance();
		}
		else error();
	}
	else if(tok == tok_SEMICOLON){
		advance();
	}
	else if(!Block())
	else if(tok == tok_IF){
		advance();
		if(tok == tok_LPAR){
			advance();
			if(!Cond())
			else error();
			if(tok == tok_RPAR){
				advance();
			}
			else error();
		}
		else error();

		if(!Stmt())
		else error();

		if(tok == tok_ELSE){
			advance();
			if(!Stmt())
			else error();
		}
		else ;
	}
	else if(tok == tok_WHILE){
		advance();
		if(tok == tok_LPAR){
			advance();
			if(!Cond())
			else error();
			if(tok == tok_RPA){
				advance();
			}
			else error();
			if(!Stmt())
			else error();
		}
		else error();
	}
	else if(tok == tok_BREAK){
		advance();
		if(tok == tok_SEMICOLON){
			advance();
		}
		else error();
	}
	else if(tok == tok_CONTINUE){
		advance();
		if(tok == tok_SEMICOLON){
			advance();
		}
		else error();
	}
	else if(tok == tok_RETURN){
		advance();
		if(!Exp())
		else ;
		if(tok == tok_SEMICOLON){
			advance();
		}
		else error();
	}
	else error();

	return 0;
}

// Exp
//		: AddExp 
int Exp(void){
	if(!AddExp())
	else error();
	
	return 0;
}

// Cond
//		: LOrExp
int Cond(void){
	if(!LOrExp())
	else error();

	return 0;
}

// LVal
//		: Ident {'[' Exp ']'}
int LVal (void){
	if(tok == tok_ID){
		advance();
		while(tok == tok_LSQUARE){
			advance();
			if(!Exp())
			else error();
			if(tok == tok_RSQUARE){
				advance();
			}
			else error();
		}
	}
	else error();

	return 0;
}

// PrimaryExp
//		：'(' Exp ')' 
//		| LVal 
//		| Number
int PrimaryExp(void){
	if(tok == tok_LPAR){
		advance();
		if(!Exp())
		else error();
		if(tok == tok_RPAR){
			advance();
		}
		else error();
	}
	else if(!LVal())
	else if(!Number())
	else error();

	return 0;
}

// Number
//		：IntConst
int Number(void){
	if(!IntConst())
	else error();

	return 0;
}

// UnaryExp
//		：PrimaryExp 
//		| Ident '(' [FuncRParams] ')'
//		| UnaryOp UnaryExp
int UnaryExp(void){
	if(!PrimaryExp())
	else if(tok == tok_ID){
		advance();
		if(tok == tok_LPAR){
			advance();
		}
		else error();
		if(!FuncRParams())
		else ;
		if(tok == tok_RPAR){
			advance();
		}
		else error();
	}
	else if(!UnaryOp()){
		if(!UnaryExp())
		else error();
	}
	else error();

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
	else error();

	return 0;
}

// FuncRParams
//		: Exp { ',' Exp }
int FuncRParams(void){
	if(!Exp()){
		while(tok == tok_COMMA){
			advance();
			if(!Exp())
			else error();
		}
	}
	else error();

	return 0;
}

// MulExp
//		: UnaryExp 
//		| MulExp ('*' | '/' | '%') UnaryExp
int MulExp(void){
	if(!UnaryExp())
	else if(!MulExp()){
		if(tok == tok_MUL || tok == tok_DIV || tok == tok_MODULO){
			advance();
		}
		else error();
		if(!UnaryExp())
		else error();
	}
	else error();

	return 0;
}

// AddExp
//		: MulExp 
//		| AddExp ('+' | '−') MulExp
int AddExp(void){
	if(!MulExp())
	else if(!AddExp()){
		if(tok == tok_ADD || tok == tok_SUB){
			advance();
		}
		else error();
		if(!MulExp())
		else error();
	}
	else error();

	return 0;
}

// RelExp
//		: AddExp 
//		| RelExp ('<' | '>' | '<=' | '>=') AddExp
int RelExp(void){
	if(!AddExp())
	else if(!RelExp()){
		if(tok == tok_LESS || tok == tok_GREAT || tok == tok_LESSEQ || tok == tok_GREATEQ){
			advance();
		}
		else error();
		if(!AddExp())
		else error();
	}
	else error();

	return 0;
}

// EqExp
//		: RelExp 
//		| EqExp ('==' | '!=') RelExp
int EqExp(void){
	if(!RelExp())
	else if(!EqExp()){
		if(tok == tok_EQ || tok == tok_NOTEQ){
			advance();
		}
		else error();
		if(!RelExp())
		else error();
	}
	else error();

	return 0;
}

// LAndExp
//		: EqExp 
//		| LAndExp '&&' EqExp
int LAndExp(void){
	if(!EqExp())
	else if(!LAndExp()){
		if(tok == tok_AND){
			advance();
		}
		else error();
		if(!EqExp())
		else error();
	}
	else error();

	return 0;

}

// LOrExp
//		: LAndExp 
//		| LOrExp '||' LAndExp
int LOrExp(void){
	if(!LAndExp())
	else if(!LOrExp()){
		if(tok == tok_OR){
			advance();
		}
		else error();
		if(!LAndExp())
		else error();
	}
	else error();
	
	return 0;
}

// ConstExp
//		: AddExp
int ConstExp(void){
	if(!AddExp())
	else error();

	return 0;
}
