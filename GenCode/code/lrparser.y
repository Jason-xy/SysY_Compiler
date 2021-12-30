%{
	#include <string.h>
    #include "tree.h"

	#define YYSTYPE Ast *

	extern FILE *fp_error;
    extern int lineno;
    extern Ast *g_root;
	extern char msg[MAX_MESSAGE_LEN];

	int yylex();
	int yyerror(const char* message);
%}

%token T_INT T_VOID
%token ASSIGN
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token CONST IF ELSE WHILE RETURN BREAK CONTINUE
%token EQUAL NOTEQUAL GRATEREQUAL LESSEQUAL GRATER LESS 
%token ADD SUB MUL DIV MOD AND OR NOT
%token IDENTIFIER CONSTANT

%start compUnit

%%


bType
: T_INT { $$ = createNode(lineno, NT_TYPE, msg);}
| T_VOID { $$ = createNode(lineno, NT_TYPE, msg); }
;

constant
: CONSTANT { 
	$$ = createNode(lineno, NT_CONSTANT, msg);
	$$->value = atoi(msg);
}

compUnit
: decl { addChild(g_root, $1); }
| funcDef { addChild(g_root, $1); }
| compUnit decl { addChild(g_root, $2); }
| compUnit funcDef { addChild(g_root, $2); }
;

lVal
: identifier { $$ = $1; }
| arrayIdentifier { $$ = $1; }
;

identifier
: IDENTIFIER { $$ = createNode(lineno, NT_VAR, msg);}
;

arrayIdentifier
: identifier LBRACKET expr RBRACKET {
    $$ = createNode(lineno, NT_OP_INDEX, "[]");
    addChild($$, $1);
    addChild($$, $3);
  }
| arrayIdentifier LBRACKET expr RBRACKET {
    $$ = createNode(lineno, NT_OP_INDEX, "[]");
    addChild($$, $1);
    addChild($$, $3);
  }
;

decl
: constDecl { $$ = $1; }
| varDecl { $$ = $1; }
;

constDecl
: CONST bType constDefs SEMICOLON {
    $$ = createNode(lineno, NT_STMT_CONSTDECL, "constDecl");
    addChild($$, $3);
};

constDefs
: constDef { $$ = createNode(lineno, NT_VARDECLLIST, "constDefs"); addChild($$, $1); }
| constDefs COMMA constDef { $$ = $1; addChild($$, $3); }
;

constDef
: identifier ASSIGN constant {
    $$ = createNode(lineno, NT_OP_ASSIGN, "=");
    addChild($$, $1);
    addChild($$, $3);
  }
| arrayIdentifier ASSIGN LBRACE arrayInitVal RBRACE {
    $$ = createNode(lineno, NT_OP_ASSIGN, "=");
    addChild($$, $1);
    addChild($$, $4);
  }
;

arrayInitVal
: constant { $$ = createNode(lineno, NT_VARLIST, "varlist"); addChild($$, $1); }
| arrayInitVal COMMA constant { $$ = $1; addChild($$, $3); }
;

varDecl
: bType varDefs SEMICOLON {
    $$ = createNode(lineno, NT_STMT_VARDECL, "vardecl");
    addChild($$, $2);
};

varDefs
: varDef { $$ = createNode(lineno, NT_VARDECLLIST, "varDefs"); addChild($$, $1); }
| varDefs COMMA varDef { $$ = $1; addChild($$, $3); }
;

varDef
: lVal { $$ = $1; }
| identifier ASSIGN expr {
	$$ = createNode(lineno, NT_OP_ASSIGN, "=");
	addChild($$, $1);
	addChild($$, $3);
  }
| arrayIdentifier ASSIGN LBRACE arrayInitVal RBRACE {
	$$ = createNode(lineno, NT_OP_ASSIGN, "=");
	addChild($$, $1);
	addChild($$, $4);  
  }
;

funcDef
: bType identifier LPAREN funcFParams RPAREN block {
    $$ = createNode(lineno, NT_STMT_FUNCDEF, "funcDef");
	addChild($$, $1);
	addChild($$, $2);
	Ast *params = createNode(lineno, NT_PARAM, "params");
	addChild(params, $4);
	addChild($$, params);
	addChild($$, $6);
}
| bType identifier LPAREN RPAREN block {
	$$ = createNode(lineno, NT_STMT_FUNCDEF, "funcDef");
	addChild($$, $1);
	addChild($$, $2);
	addChild($$, $5);
}

funcFParams
: funcFParam { $$ = $1; }
| funcFParams COMMA funcFParam { $$ = $1; addSibling($$, $3); }
;

funcFParam
: bType lVal {
	$$ = createNode(lineno, NT_PARAM, "param");
	addChild($$, $1);
	addChild($$, $2);
};

block
: LBRACE blockItems RBRACE {
	$$ = createNode(lineno, NT_STMT_BLOCK, "block");
	addChild($$, $2);
};

blockItems
: blockItem { $$ = $1; }
| blockItems blockItem { $$ = $1; addSibling($$, $2); }
;

blockItem
: decl { $$ = $1; }
| stmt { $$ = $1; }
;

stmt
: SEMICOLON { $$ = NULL; }
| expr SEMICOLON { $$ = $1; }
| block { $$ = $1; }
| lVal ASSIGN expr SEMICOLON {
	$$ = createNode(lineno, NT_OP_ASSIGN, "=");
	addChild($$, $1);
	addChild($$, $3);
}
| IF LPAREN cond RPAREN stmt ELSE stmt {
	$$ = createNode(lineno, NT_STMT_IFELSE, "ifelse");
	addChild($$, $3);
	addChild($$, $5);
	addChild($$, $7);
}
| IF LPAREN cond RPAREN stmt {
	$$ = createNode(lineno, NT_STMT_IFELSE, "if");
	addChild($$, $3);
	addChild($$, $5);
}
| WHILE LPAREN cond RPAREN stmt {
	$$ = createNode(lineno, NT_STMT_WHILE, "while");
	addChild($$, $3);
	addChild($$, $5);
}
| BREAK SEMICOLON { $$ = createNode(lineno, NT_STMT_BREAK, "break"); }
| CONTINUE SEMICOLON { $$ = createNode(lineno, NT_STMT_CONTINUE, "continue"); }
| RETURN SEMICOLON { $$ = createNode(lineno, NT_STMT_RETURN, "return"); }
| RETURN expr SEMICOLON {
	$$ = createNode(lineno, NT_STMT_RETURN, "return");
	addChild($$, $2);
};


expr
: addExpr { $$ = $1; }
;

cond
: lOrExpr { $$ = $1; }
;

addExpr
: mulExpr { $$ = $1; }
| addExpr ADD mulExpr { 
	$$ = createNode(lineno, NT_OP_ADD, "+");
	addChild($$, $1);
	addChild($$, $3);
}
| addExpr SUB mulExpr {
	$$ = createNode(lineno, NT_OP_SUB, "-");
	addChild($$, $1);
	addChild($$, $3);
}
;

mulExpr
: unaryExpr { $$ = $1; }
| mulExpr MUL unaryExpr {
	$$ = createNode(lineno, NT_OP_MUL, "*"); 
	addChild($$, $1); 
	addChild($$, $3);
}
| mulExpr DIV unaryExpr {
	$$ = createNode(lineno, NT_OP_DIV, "/"); 
	addChild($$, $1); 
	addChild($$, $3);
}
| mulExpr MOD unaryExpr {
	$$ = createNode(lineno, NT_OP_MOD, "%%"); 
	addChild($$, $1); 
	addChild($$, $3);
}
;

unaryExpr
: primaryExpr { $$ = $1; }
| ADD expr {
	$$ = createNode(lineno, NT_OP_POS, "+"); 
	addChild($$, $2);
}
| SUB expr {
	$$ = createNode(lineno, NT_OP_NEG, "-"); 
	addChild($$, $2);
}
| NOT cond {
	$$ = createNode(lineno, NT_OP_NOT, "!"); 
	addChild($$, $2);
}
;

primaryExpr
: LPAREN expr RPAREN { $$ = $2; }
| identifier LPAREN funcRParams RPAREN {
	$$ = createNode(lineno, NT_FUNCCALL, "funcCall");
	addChild($$, $1);
	addChild($$, $3);
  }
| identifier LPAREN RPAREN {
	$$ = createNode(lineno, NT_FUNCCALL, "funcCall");
	addChild($$, $1);
  }
| lVal { $$ = $1; }
| constant { $$ = $1; }
;

funcRParams
: expr {
	$$ = createNode(lineno, NT_VARLIST, "varlist"); 
	addChild($$, $1);
}
| funcRParams COMMA expr {
	$$ = $1; 
	addChild($$, $3);
}
;

lOrExpr
: lAndExpr { $$ = $1; }
| lOrExpr OR lAndExpr {
	$$ = createNode(lineno, NT_OP_OR, "||"); 
	addChild($$, $1); 
	addChild($$, $3);
}
;

lAndExpr
: eqExpr { $$ = $1; }
| lAndExpr AND eqExpr {
	$$ = createNode(lineno, NT_OP_AND, "&&"); 
	addChild($$, $1); 
	addChild($$, $3);
}
;

eqExpr
: relExpr { $$ = $1; }
| eqExpr EQUAL relExpr {
	$$ = createNode(lineno, NT_OP_E, "=="); 
	addChild($$, $1); 
	addChild($$, $3);
}
| eqExpr NOTEQUAL relExpr {
	$$ = createNode(lineno, NT_OP_NE, "!="); 
	addChild($$, $1); 
	addChild($$, $3);
}
;

relExpr
: expr { $$ = $1; }
| relExpr GRATER expr {
	$$ = createNode(lineno, NT_OP_G, ">"); 
	addChild($$, $1); 
	addChild($$, $3);
}
| relExpr LESS expr {
	$$ = createNode(lineno, NT_OP_L, "<"); 
	addChild($$, $1); 
	addChild($$, $3);
}
| relExpr GRATEREQUAL expr {
	$$ = createNode(lineno, NT_OP_GE, ">="); 
	addChild($$, $1); 
	addChild($$, $3);
}
| relExpr LESSEQUAL expr {
	$$ = createNode(lineno, NT_OP_LE, "<="); 
	addChild($$, $1); 
	addChild($$, $3);
}
;



%%

int yyerror(const char* message)
{
	fprintf(fp_error, "error: %s, at line %d\n", message, lineno);
	return -1;
}