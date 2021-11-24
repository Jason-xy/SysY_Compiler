%{

#include <stdio.h>
#include "tok.h"
#incldue "ast.h"

int yylex(void);
void yyerror(char *);

past root = newAstNode_parameter(" ", "CompUnit", NULL, NULL, NULL)

%}

%token  tok_ID,		 // 标识符
%token	tok_INTEGER,	 // 整数
%token	tok_INT,		 // int
%token	tok_VOID,		 // void
%token	tok_CONST,		 // const
%token	tok_IF,			 // if
%token	tok_ELSE,		 // else
%token	tok_WHILE,		 // while
%token	tok_BREAK,		 // break
%token	tok_CONTINUE,	 // continue
%token	tok_RETURN,		 // return
%token	tok_ADD,		 // +
%token	tok_SUB,		 // -
%token	tok_MUL,		 // *
%token	tok_DIV,		 // /
%token	tok_MODULO,		 // %
%token	tok_LESS,		 // <
%token	tok_LESSEQ,		 // <=
%token	tok_GREAT,		 // >
%token	tok_GREATEQ,	 // >=
%token	tok_NOTEQ,		 // !=
%token	tok_EQ,		 	 // ==
%token	tok_NOT,		 // !
%token	tok_AND, 		 // &&
%token	tok_OR,			 // ||
%token	tok_ASSIGN,		 // =
%token	tok_LPAR,		 // (
%token	tok_RPAR,		 // )
%token	tok_LBRACKET,	 // {
%token	tok_RBRACKET,	 // }
%token	tok_LSQUARE,	 // [
%token	tok_RSQUARE,	 // ]
%token	tok_COMMA,		 // ,
%token	tok_SEMICOLON	 // ;

%%
//ident
declCompIdentifier
: pDeclIdentifier
| constArrayIdentifier
;

pDeclIdentifier
: declIdentifier {$$ = new TreeNode($1);}
| MUL pDeclIdentifier {$$ = $2; $$->pointLevel++;}
| ADDR pDeclIdentifier {$$ = $2; $$->pointLevel--;}
;

// 常量数组标识符（仅供声明使用）
constArrayIdentifier
: pDeclIdentifier LBRACKET INTEGER RBRACKET {
  $$ = $1;
  $$->type = new Type(VALUE_ARRAY);
  $$->type->elementType = $1->type->type;
  $$->type->dimSize[$$->type->dim] = $3->int_val;
  $$->type->dim++;
}
| constArrayIdentifier LBRACKET INTEGER RBRACKET {
  $$ = $1;
  $$->type->dimSize[$$->type->dim] = $3->int_val;
  $$->type->dim++;
}
;

declIdentifier
: IDENTIFIER {
	$$ = $1;
	$$->var_scope = presentScope;
	#ifdef ID_REDUCE_DEBUG
		cout<<"$ reduce declIdentifier : "<<$$->var_name<<", at scope :"<<presentScope<<endl;
	#endif
	if (idList.count(make_pair($$->var_name, $$->var_scope)) != 0) {
		string t = "Redeclared identifier : " + $$->var_name;
		yyerror(t.c_str());
	}
	idNameList.insert(make_pair($$->var_name, $$->var_scope));
	idList[make_pair($$->var_name, $$->var_scope)] = $$;
}
;

CompUnit
：Decl {root->left = newAstChild($1);}
| FuncDef {root->left = newAstChild($1);}
| CompUnit Decl {root->left = newAstChild($2);}
| CompUnit FuncDef {root->left = newAstChild($2);}
;

Decl
: ConstDecl 
| VarDecl 
;

ConstDecl
: tok_CONST BType ConstDefs tok_SEMICOLON {
  $$ = newAstNode_parameter("", "ConstDecl", NULL, NULL, NULL);
  $$->newAstChildNext($2);
  $$->newAstChild($3);}
;

ConstDefs
: constDef {$$ = newAstNode_parameter("", "ConstDef", NULL, NULL, NULL); $$->newAstChild($1);}
| constDefs COMMA constDef {$$ = $1; $$->newAstChild($3);}
;

constDef
: pDeclIdentifier tok_ASSIGN tok_INTEGER {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_ASSIGN; $$->addChild($1); $$->addChild($3);}
| constArrayIdentifier tok_ASSIGN tok_LBRACKET ArrayInitVal tok_RBRACKET {$$ = new TreeNode(lineno, NODE_OP); $$->optype = OP_ASSIGN; $$->addChild($1); $$->addChild($4);}
;

%%