/*
 ============================================================================
@Author      : JasonHsu
@Date        : 2021-11-16
@Name        : rdparser.c
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tok.h"

extern int yylex();
extern void yyputback(char *yytext);
extern FILE *yyin;
extern char *yytext;
extern char *yyID;
extern int yyNUM;

// build AST
// Each non-terminator corresponds to a function
typedef struct _ast ast;
typedef struct _ast *past;
union astValue
{
	int ivalue;
	char *svalue;
};
struct _ast
{
	union astValue value;
	char *nodeType;
	past left;
	past right;
	past next;
};
void showAst(past node, int nest);
past newExpr(int oper, past left, past right, past next);
past newIdent(char *strVal, past next);
past newType(int type);
past newNum(int value, past next);
past newAstNode_parameter(char *strVal, char *nodeType, past left, past right, past next);
past newAstNode(void);
past astCompUnit(void);
past astDecl(void);
past astConstDecl(void);
past astBType(void);
past astConstDef(void);
past astConstInitVal(void);
past astVarDecl(void);
past astVarDef(void);
past astInitVal(void);
past astFuncDef(void);
past astFuncType(void);
past astFuncFParams(void);
past astFuncFParam(void);
past astBlock(void);
past astBlockItem(void);
past astStmt(void);
past astExp(void);
past astCond(void);
past astLVal(void);
past astPrimaryExp(void);
past astNumber(void);
past astUnaryExp(void);
past astUnaryOp(void);
past astFuncRParams(void);
past astMulExp(void);
past astAddExp(void);
past astRelExp(void);
past astEqExp(void);
past astLAndExp(void);
past astLOrExp(void);
past astConstExp(void);

int tok;

void advance(void)
{
	tok = yylex();
	printf("tok: %d    %s\n", tok, yytext);
}

void error(void)
{
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
	setbuf(stdout, NULL);
	// yyin = fopen("../../test_cases/59_sort_test7.c", "r");
	yyin = fopen("test.c", "r");
	advance();
	past r = astCompUnit();
	showAst(r, 0);
	// printf("result: %d\n", r);
	//  past rr = astExpr();
	//  showAst(rr, 0);

	return 0;
}

past newAstNode(void)
{
	past node = malloc(sizeof(ast));
	if (node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	return node;
}

past newAstNode_parameter(char *strVal, char *nodeType, past left, past right, past next)
{
	past node = (past)malloc(sizeof(ast));
	if (node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	node->value.svalue = strVal;
	node->nodeType = nodeType;
	node->left = left;
	node->right = right;
	node->next = next;
	return node;
}

past newNum(int value, past next)
{
	past var = newAstNode();
	var->nodeType = "intValue";
	var->value.ivalue = value;
	var->next = next;
	return var;
}

past newType(int type)
{
	past var = newAstNode();
	var->nodeType = "type";
	switch (type)
	{
	case tok_VOID:
		var->value.svalue = "VOID";
		break;
	case tok_INT:
		var->value.svalue = "INT";
		break;
	case tok_CONST:
		var->value.svalue = "CONST";
		break;
	default:
		break;
	}
	var->left = NULL;
	var->right = NULL;
	var->next = NULL;
}

past newIdent(char *strVal, past next)
{
	past var = newAstNode();
	var->nodeType = "varDecl";
	var->value.svalue = strVal;
	var->next = next;
	return var;
}

past newExpr(int oper, past left, past right, past next)
{
	past var = newAstNode();
	switch (oper)
	{
	case tok_LESSEQ:
		var->value.svalue = "<=";
		break;
	case tok_GREATEQ:
		var->value.svalue = ">=";
		break;
	case tok_NOTEQ:
		var->value.svalue = "!=";
		break;
	case tok_EQ:
		var->value.svalue = "==";
		break;
	case tok_AND:
		var->value.svalue = "&&";
		break;
	case tok_OR:
		var->value.svalue = "||";
		break;
	default:
		var->value.svalue = "@";
		break;
	}
	var->nodeType = "expr";
	// var->ivalue = oper;
	var->left = left;
	var->right = right;
	var->next = next;
	return var;
}

void showAst(past node, int nest)
{
	if (node == NULL)
		return;
	int i = 0;
	for (i = 0; i < nest; i++)
		printf("  ");
	if (strcmp(node->nodeType, "intValue") == 0)
		printf("%s    .    %d\n", node->nodeType, node->value.ivalue);
	else if (strcmp(node->nodeType, "decl") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "constDecl") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "constDef") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "varDef") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "constInitVal") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "initVal") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "funcDef") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "FuncFParams") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "FuncFParam") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "noexp") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "CompUnit") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "expr") == 0)
	{
		if (strcmp(node->value.svalue, "@") == 0)
			printf("%s    .    '%c'\n", node->nodeType, (char)node->value.ivalue);
		else
			printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	}
	else if (strcmp(node->nodeType, "list") == 0)
		printf("%s    .    %d\n", node->nodeType, node->value.ivalue);
	else if (strcmp(node->nodeType, "varDecl") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "arrayDecl") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "funcDecl") == 0 || strcmp(node->nodeType, "blockDecl") == 0)
		printf("%s    .    \n", node->nodeType);
	else if (strcmp(node->nodeType, "parameter") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "type") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "arrayDecl") == 0)
		printf("%s    .    %s\n", node->nodeType, node->value.svalue);
	else if (strcmp(node->nodeType, "AssignStmt") == 0 || strcmp(node->nodeType, "IfStmt") == 0 || strcmp(node->nodeType, "WhileStmt") == 0 || strcmp(node->nodeType, "BreakStmt") == 0 || strcmp(node->nodeType, "ContinueStmt") == 0 || strcmp(node->nodeType, "ReturnStmt") == 0 || strcmp(node->nodeType, "EmptyStmt") == 0 || strcmp(node->nodeType, "expStmt") == 0)
		printf("%s    .    \n", node->nodeType);

	showAst(node->left, nest + 1);
	showAst(node->right, nest + 1);
	showAst(node->next, nest);
}

// CompUnit
//		：Decl
//		| FuncDef
//		| CompUnit Decl
//		| CompUnit FuncDef
past astCompUnit(void)
{
	past root = newAstNode_parameter("", "CompUnit", NULL, NULL, NULL);
	past tmp = root;
	if (tok == tok_CONST || tok == tok_VOID || tok == tok_INT)
	{
		if (tok == tok_CONST)
		{
			tmp->left = astDecl();
			if (tmp->left == NULL)
				return NULL;
		}
		else if (tok == tok_VOID)
		{
			tmp->left = astFuncDef();
			if (tmp->left == NULL)
				return NULL;
		}
		else
		{
			char *s0 = strdup(yytext);
			advance();
			if (tok == tok_ID)
			{
				char *s1 = strdup(yytext);
				advance();
				if (tok == tok_LPAR)
				{
					yyputback(yytext);
					yyputback(s1);
					yyputback(s0);
					advance();
					tmp->next = astFuncDef();
					if (tmp->next == NULL)
						return NULL;
				}
				else
				{
					yyputback(yytext);
					yyputback(s1);
					yyputback(s0);
					advance();
					tmp->next = astDecl();
					if (tmp->next == NULL)
						return NULL;
				}
			}
			else
				return NULL;
		}
	}
	else
		return NULL;
	while (1)
	{
		if (tok == '\n' || tok == EOF || tok == 0)
		{
			return root;
		}
		if (tok == tok_CONST || tok == tok_VOID || tok == tok_INT)
		{
			tmp = tmp->next;
			if (tok == tok_CONST)
			{
				tmp->left = astDecl();
				if (tmp->left == NULL)
				{
					printf("[Error]: astDecl()\n");
					return NULL;
				}
			}
			else if (tok == tok_VOID)
			{
				tmp->left = astFuncDef();
				if (tmp->left == NULL)
				{
					printf("[Error]: astFuncDef()\n");
					return NULL;
				}
			}
			else
			{
				char *s0 = strdup(yytext);
				advance();
				if (tok == tok_ID)
				{
					char *s1 = strdup(yytext);
					advance();
					if (tok == tok_LPAR)
					{
						yyputback(yytext);
						yyputback(s1);
						yyputback(s0);
						advance();
						tmp->next = astFuncDef();
						if (tmp->next == NULL)
						{
							printf("[Error]: astFuncDef()\n");
							return NULL;
						}
					}
					else
					{
						yyputback(yytext);
						yyputback(s1);
						yyputback(s0);
						advance();
						tmp->next = astDecl();
						if (tmp->next == NULL)
						{
							printf("[Error]: astDecl()\n");
							return NULL;
						}
					}
				}
				else
					return NULL;
			}
		}
		else
			return NULL;
	}

	return root;
}

// Decl
//		: ConstDecl
//		| VarDecl
past astDecl(void)
{
	past root = newAstNode_parameter("", "decl", NULL, NULL, NULL);
	past tmp = root;
	if (tok == tok_CONST)
	{
		root->left = astConstDecl();
		if (root->left == NULL)
		{
			printf("[Error]: astConstDecl()\n");
			return NULL;
		}
	}
	else if (tok == tok_INT)
	{
		root->left = astVarDecl();
		if (root->left == NULL)
		{
			printf("[Error]: astVarDecl()\n");
			return NULL;
		}
	}
	else
		return NULL;

	return root;
}

// ConstDecl
//		: 'const' BType ConstDef { ',' ConstDef } ';'
past astConstDecl(void)
{
	past root = newAstNode_parameter("", "ConstDecl", NULL, NULL, NULL);
	past tmp = root;
	// 'const'
	if (tok == tok_CONST)
	{
		advance();
		// BType
		tmp->next = astBType();
		if (tmp->left == NULL)
		{
			printf("[Error]: astBType()\n");
			return NULL;
		}
		tmp = tmp->left;
		// ConstDef
		tmp->left = astConstDef();
		if (tmp->left == NULL)
		{
			printf("[Error]: astConstDef()\n");
			return NULL;
		}
		tmp = tmp->left;
		// { ',' ConstDef }
		while (tok == tok_COMMA)
		{
			advance();
			tmp->next = astConstDef();
			if (tmp->next == NULL)
			{
				printf("[Error]: astConstDef()\n");
				return NULL;
			}
			tmp = tmp->next;
		}
		// ';'
		if (tok == tok_SEMICOLON)
		{
			advance();
			return root;
		}
		else
			return NULL;
	}
	else
		return NULL;
	return root;
}

// BType
//		: 'int'
past astBType(void)
{
	past root = NULL;
	if (tok == tok_INT)
	{
		root = newType(tok);
		advance();
	}
	else
		printf("[Error]: astBType()\n");
	return root;
}

// ConstDef
//		: Ident { '[' ConstExp ']' } '=' ConstInitVal
past astConstDef(void)
{
	past root = newAstNode_parameter("", "ConstDef", NULL, NULL, NULL);
	past tmp = root;
	// Ident
	if (tok == tok_ID)
	{
		past id = newIdent(strdup(yytext), NULL);
		tmp->left = id;
		tmp = tmp->left;
		advance();
		// { '[' ConstExp ']' }
		while (tok == tok_LSQUARE)
		{
			advance();
			// ConstExp
			tmp->next = astConstExp();
			if (tmp->next == NULL)
			{
				printf("[Error]: astConstExp()\n");
				return NULL;
			}
			tmp = tmp->next;
			// ']'
			if (tok == tok_RSQUARE)
			{
				advance();
			}
			else
				return NULL;
		}
		// '='
		if (tok == tok_ASSIGN)
		{
			advance();
			// ConstInitVal
			tmp->left = astConstInitVal();
			if (tmp->left == NULL)
			{
				printf("[Error]: astConstInitVal()\n");
				return NULL;
			}
			tmp = tmp->left;
		}
		else
			return NULL;
	}
	else
		return NULL;

	return root;
}

// ConstInitVal
//		: ConstExp
//		| '{' [ ConstInitVal { ',' ConstInitVal } ] '}'
past astConstInitVal(void)
{
	past list = newAstNode_parameter("", "list", NULL, NULL, NULL);
	past root = newAstNode_parameter("", "ConstInitVal", list, NULL, NULL);
	list->value.ivalue = 0;
	past tmp = list;
	// ConstExp
	if (tok == tok_LBRACKET)
	{
		advance();
		// [ ConstInitVal { ',' ConstInitVal } ]
		tmp->left = astConstInitVal();
		if (tmp->left == NULL)
		{
			printf("[Error]: astConstInitVal()\n");
			return NULL;
		}
		tmp = tmp->left;
		while (tok == tok_COMMA)
		{
			advance();
			tmp->next = astConstInitVal();
			if (tmp->next == NULL)
			{
				printf("[Error]: astConstInitVal()\n");
				return NULL;
			}
			tmp = tmp->next;
		}
		// '}'
		if (tok == tok_RBRACKET)
		{
			advance();
			return root;
		}
		else
			return NULL;
	}
	else
	{
		tmp->value.ivalue++;
		tmp->left = astConstExp();
		if (tmp->left == NULL)
		{
			printf("[Error]: astConstExp()\n");
			return NULL;
		}
	}

	return root;
}

// VarDecl
//		: BType VarDef { ',' VarDef } ';'
past astVarDecl(void)
{
	past tmp = NULL;
	if (tok == tok_INT)
	{
		past type = newType(tok);
		past item = newAstNode_parameter("", "list", NULL, NULL, NULL);
		past root = newAstNode_parameter("", "varDecl", type, item, NULL);
		root->right->value.ivalue = 0;
		advance();
		if (tok == tok_ID)
		{
			past var = astVarDef();
			item->value.ivalue++;
			item->left = var;
			tmp = var;
		}
		while (tok == tok_COMMA)
		{
			advance();
			item->value.ivalue++;
			tmp->next = astVarDef();
			tmp = tmp->next;
		}
		if (tok == tok_SEMICOLON)
		{
			advance();
			return root;
		}
		else
		{
			printf("[Error]: astVarDecl()\n");
			return NULL;
		}
	}
	else
	{
		printf("[Error]: astVarDecl()\n");
		return NULL;
	}
}

// VarDef
//		: Ident { '[' ConstExp ']' }
//		| Ident { '[' ConstExp ']' } '=' InitVal
past astVarDef(void)
{
	past root = NULL;
	if (tok == tok_ID)
	{
		past l = newAstNode_parameter(strdup(yytext), "varDecl", NULL, NULL, NULL);
		root = newAstNode_parameter(".", "varDef", l, NULL, NULL);
		advance();
		past list = newAstNode_parameter("", "list", NULL, NULL, NULL);
		root->left->left = list;
		root->left->left->value.ivalue = 0;
		past tmp = NULL;
		if (tok == tok_LSQUARE)
		{
			root->left->nodeType = "arrayDecl";
			advance();
			past head = astConstExp();
			root->left->left->left = head;
			root->left->left->value.ivalue++;
			past tmp = head;
			if (tok == tok_RSQUARE)
			{
				advance();
				while (tok == tok_LSQUARE)
				{
					advance();
					past first = astConstExp();
					tmp->next = first;
					tmp = tmp->next;
					root->left->left->value.ivalue++;
					if (tok == tok_RSQUARE)
					{
						advance();
					}
				}
				if (tok == tok_ASSIGN)
				{
					advance();
					past init = astInitVal();
					root->right = init;
					return root;
				}
				else
				{
					return root;
				}
			}
		}
		else if (tok == tok_ASSIGN)
		{
			advance();
			past rightnode = astInitVal();
			root->right = rightnode;
			return root;
		}
		else
		{
			return root;
		}
	}
	else
		return NULL;

	return root;
}

// InitVal
//		: Exp
//		| '{' [ InitVal { ',' InitVal } ] '}'
past astInitVal(void)
{
	past list = newAstNode_parameter("", "list", NULL, NULL, NULL);
	past root = newAstNode_parameter("", "initVal", list, NULL, NULL);
	list->value.ivalue = 0;
	past tmp = list;
	if (tok == tok_LBRACKET)
	{
		advance();
		// [ InitVal { ',' InitVal } ]
		tmp->left = astInitVal();
		if (tmp->left != NULL)
		{
			tmp = tmp->left;
			list->value.ivalue++;

			// { ',' InitVal }
			while (tok == tok_COMMA)
			{
				advance();
				tmp->next = astInitVal();
				if (tmp->next == NULL)
					return NULL;
				tmp = tmp->next;
				list->value.ivalue++;
			}
		}

		if (tok == tok_RBRACKET)
		{
			advance();
		}
		else
			return NULL;
	}
	else
	{
		list->value.ivalue++;
		list->left = astExp();
		if (list->left != NULL)
			return root;
		else
		{
			printf("[Error]: astConstInitVal()\n");
			return NULL;
		}
	}

	return root;
}

// FuncDef
//		: FuncType Ident '(' [FuncFParams] ')' Block
past astFuncDef(void)
{
	past root = newAstNode();
	root->nodeType = "funcDef";
	if (tok == tok_VOID || tok == tok_INT)
	{
		past type = astFuncType();
		root->left = type;
		if (tok == tok_ID)
		{
			past id = newIdent(strdup(yytext), NULL);
			type->left = id;
			advance();
			if (tok == tok_LPAR)
			{
				advance();
				if (tok != tok_RPAR)
				{
					past funcFP = astFuncFParams();
					id->left = funcFP;
					advance();
				}
				else
				{
					advance();
				}
				past block = astBlock();
				root->right = block;
				return root;
			}
			else
			{
				printf("[Error]: astFuncDef()\n");
				return NULL;
			}
		}
		else
		{
			printf("[Error]: astFuncDef()\n");
			return NULL;
		}
	}
	else
	{
		printf("[Error]: astFuncDef()\n");
		return NULL;
	}

	return root;
}

// FuncType
//		: 'void'
//		| 'int'
past astFuncType(void)
{
	past root = NULL;
	if (tok == tok_VOID || tok == tok_INT)
	{
		root = newType(tok);
		advance();
	}
	else
	{
		printf("[Error]: astFuncType()\n");
		return NULL;
	}
	return root;
}

// FuncFParams
//		: FuncFParam { ',' FuncFParam }
past astFuncFParams(void)
{
	int list = 0;
	past l = newAstNode_parameter("", "list", NULL, NULL, NULL);
	past root = newAstNode_parameter("", "FuncFParams", l, NULL, NULL);
	root->left->value.ivalue = list;
	past head = astFuncFParam();
	root->left->left = head;
	root->left->value.ivalue++;
	while (tok == tok_COMMA)
	{
		advance();
		root->left->value.ivalue++;
		head->next = astFuncFParam();
		if (head->next == NULL)
		{
			printf("[Error]: astFuncFParam()\n");
			return NULL;
		}
		head = head->next;
	}
	return root;
}

// FuncFParam
//		: BType Ident ['[' ']' { '[' Exp ']' }]
past astFuncFParam(void)
{
	int list = 0;
	past leftint = astBType();
	past root = NULL;
	if (tok == tok_ID)
	{
		past r = newIdent(strdup(yytext), NULL);
		past root = newAstNode_parameter("", "FuncFParam", leftint, r, NULL);
		advance();
		past listnode = newAstNode_parameter("", "list", NULL, NULL, NULL);
		root->right->left = listnode;
		root->right->left->value.ivalue = list;
		past tmp = NULL;
		if (tok == tok_LSQUARE)
		{
			advance();
			if (tok == tok_RSQUARE)
			{
				past head = newAstNode_parameter("", "noexp", NULL, NULL, NULL);
				root->right->left->left = head;
				root->right->left->value.ivalue++;
				tmp = head;
				advance();
				while (tok == tok_LSQUARE)
				{
					advance();
					tmp->next = astExp();
					if (tmp->next == NULL)
					{
						printf("[Error]: astExp()\n");
						return NULL;
					}
					tmp = tmp->next;
					root->right->left->value.ivalue++;
					if (tok == tok_RSQUARE)
					{
						advance();
					}
				}
				return root;
			}
		}
		else
		{
			return root;
		}
	}
	else
		return NULL;

	return root;
}

// Block
//		: '{' { BlockItem } '}'
past astBlock(void)
{
	past list = newAstNode_parameter("", "list", NULL, NULL, NULL);
	list->value.ivalue = 0;
	past block = newAstNode_parameter("", "blockDecl", NULL, NULL, NULL);
	list->left = block;
	past tmp = block;
	if (tok == tok_LBRACKET)
	{
		advance();
		if (tok != tok_RBRACKET)
		{
			list->value.ivalue++;
			block->left = astBlockItem();
			if (block->left == NULL)
			{
				printf("[Error]: astBlockItem()\n");
				return NULL;
			}
			tmp = block->left;
		}
		while (tok != tok_RBRACKET)
		{
			list->value.ivalue++;
			tmp->left = astBlockItem();
			if (tmp->left == (void *)(0x10) || tmp->left == NULL)
			{
				printf("[Error]: astBlockItem()\n");
				return NULL;
			}
			tmp = tmp->left;
		}
	}
	advance();
	return list;
}

// BlockItem
//		: Decl
//		| Stmt
past astBlockItem(void)
{
	if (tok == tok_CONST || tok == tok_INT)
	{
		return astDecl();
	}
	else
	{
		return astStmt();
	}
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
past astStmt(void)
{
	past root = NULL;
	if (tok == tok_ID)
	{
		char *s0 = strdup(yytext);
		advance();
		yyputback(yytext);
		yyputback(s0);
		if (tok == tok_LPAR)
		{
			advance();
			root = astExp();
			if (root != NULL)
			{
				if (tok == tok_SEMICOLON)
				{
					advance();
				}
				else
				{
					printf("[Error]: astExp()->tok_SEMICOLON\n");
					return NULL;
				}
			}
			else
			{
				printf("[Error]: astExp()\n");
				return NULL;
			}
		}
		else
		{
			advance();
			root = astLVal();
			if (root != NULL)
			{
				if (tok == tok_ASSIGN)
				{
					advance();
					past exp = astExp();
					past head = newAstNode_parameter("", "AssignStmt", root, exp, NULL);
					if (tok == tok_SEMICOLON)
					{
						advance();
						return head;
					}
				}
				else
				{
					printf("[Error]: astExp()->tok_ID->tok_ASSIGN\n");
					return NULL;
				}
			}
		}
	}
	else if (tok == tok_IF)
	{
		int list = 1;
		root = newAstNode();
		root->nodeType = "IfStmt";
		root->right = newAstNode_parameter("", "list", NULL, NULL, NULL);
		root->right->value.ivalue = list;
		advance();
		if (tok == tok_LPAR)
		{
			advance();
			past cond = astCond();
			root->left = cond;
			if (tok == tok_RPAR)
			{
				advance();
				if (root->right->left = astStmt())
				{
					if (tok == tok_ELSE)
					{
						advance();
						if (root->right->right = astStmt())
						{
							root->right->value.ivalue++;
							return root;
						}
						else
						{
							printf("[Error]: astExp()->tok_IF->tok_LPAR->tok_RPAR->tok_ELSE\n");
							return NULL;
						}
					}
					return root;
				}
				else
				{
					printf("[Error]: astExp()->tok_IF->tok_LPAR->tok_RPAR->astStmt()\n");
					return NULL;
				}
			}
			else
			{
				printf("[Error]: astStmt()->tok_IF->tok_RPAR\n");
				return NULL;
			}
		}
		else
		{
			printf("[Error]: astStmt()->tok_IF\n");
			return NULL;
		}
	}
	else if (tok == tok_WHILE)
	{
		root = newAstNode_parameter("", "WhileStmt", NULL, NULL, NULL);
		advance();
		if (tok == tok_LPAR)
		{
			advance();
			past cond = astCond();
			root->left = cond;
			if (tok == tok_RPAR)
			{
				advance();
				if (root->right = astStmt())
				{
					return root;
				}
				else
				{
					printf("[Error]: astStmt()->tok_WHILE\n");
					return NULL;
				}
			}
			else
			{
				printf("[Error]: astStmt()->tok_WHILE\n");
				return NULL;
			}
		}
		else
		{
			printf("[Error]: astStmt()->tok_WHILE\n");
			return NULL;
		}
	}
	else if (tok == tok_BREAK)
	{
		root = newAstNode_parameter("", "BreakStmt", NULL, NULL, NULL);
		advance();
		if (tok == tok_SEMICOLON)
		{
			advance();
			return root;
		}
	}
	else if (tok == tok_CONTINUE)
	{
		root = newAstNode_parameter("", "ContinueStmt", NULL, NULL, NULL);
		advance();
		if (tok == tok_SEMICOLON)
		{
			advance();
			return root;
		}
	}
	else if (tok == tok_RETURN)
	{
		root = newAstNode_parameter("", "ReturnStmt", NULL, NULL, NULL);
		advance();
		root->left = astExp();
		if (tok == tok_SEMICOLON)
		{
			advance();
			return root;
		}
	}
	else if (tok == tok_LBRACKET)
	{
		return astBlock();
	}
	else if (tok == tok_SEMICOLON)
	{
		root = newAstNode_parameter("", "EmptyStmt", NULL, NULL, NULL);
		advance();
		return root;
	}
	else
	{
		past root = newAstNode_parameter("", "expStmt", NULL, NULL, NULL);
		if (root->left = astExp())
		{
			if (tok == tok_SEMICOLON)
			{
				advance();
				return root;
			}
			return NULL;
		}
		return NULL;
	}
	return root;
}

// Exp: AddExp
//		: AddExp
past astExp()
{
	past a = astAddExp();
	return a;
}

// Cond
//		: LOrExp
past astCond(void)
{
	past a = astLOrExp();
	return a;
}

// LVal
//		: Ident {'[' Exp ']'}
past astLVal(void)
{
	int flag = 1;
	if (tok != tok_ID)
		return NULL;
	past root = newIdent(strdup(yytext), NULL);
	past tmp;
	advance();
	while (tok == tok_LSQUARE)
	{
		advance();
		past exp = astExp();
		if (flag == 1)
		{
			root->left = exp;
			root->nodeType = "arrayDecl";
			tmp = exp;
			flag++;
		}
		else
		{
			tmp->next = exp;
			tmp = tmp->next;
		}
		if (tok == tok_RSQUARE)
			advance();
		else
		{
			printf("[Error]: LVal()\n");
			return NULL;
		}
	}
	return root;
}

// PrimaryExp
//		：'(' Exp ')'
//		| LVal
//		| Number
past astPrimaryExp(void)
{
	if (tok == tok_LPAR)
	{
		advance();
		past pri = astExp();
		if (tok == tok_RPAR)
		{
			advance();
			return pri;
		}
		else
			printf("[Error]: astPrimaryExp()->tok_LPAR\n");
	}
	else if (tok == tok_ID)
		return astLVal();
	else if (tok == tok_INTEGER)
		return astNumber();
	else
		printf("[Error]: astPrimaryExp()\n");
	return NULL;
}

// Number
//		：IntConst
past astNumber(void)
{
	if (tok == tok_INTEGER)
	{
		past num = newNum(yyNUM, NULL);
		advance();
		return num;
	}
	return NULL;
}

// UnaryExp
//		：PrimaryExp
//		| Ident '(' [FuncRParams] ')'
//		| UnaryOp UnaryExp
past astUnaryExp(void)
{
	past ue = NULL;
	past root = NULL;
	if (tok == tok_ADD || tok == tok_SUB || tok == tok_NOT)
	{
		while (tok == tok_ADD || tok == tok_SUB || tok == tok_NOT)
		{
			int oper = tok;
			advance();
			ue = astUnaryExp();
			ue = newExpr(oper, NULL, ue, NULL);
		}
		advance();
		return ue;
	}
	else if (tok == tok_ID)
	{
		char *s1 = strdup(yytext);
		ue = newIdent(strdup(yytext), NULL);
		advance();
		if (tok == tok_LPAR)
		{
			advance();
			if (tok == tok_RPAR)
			{
				advance();
				return ue;
			}
			else
			{
				past root = newAstNode();
				root->nodeType = "funcDecl";
				root->left = ue;
				past funcRP = astFuncRParams();
				root->right = funcRP;
				if (tok == tok_RPAR)
				{
					advance();
					return root;
				}
				else
					printf("[Error]: astUnaryExp()\n");
			}
			return NULL;
		}
		// PrimaryExp.LVal
		else
		{
			if (tok == tok_RPAR)
				return ue;
			yyputback(strdup(yytext));
			yyputback(s1);
			advance();
			return astLVal();
		}
	}
	else
	{
		root = astPrimaryExp();
		return root;
	}

	return root;
}

// FuncRParams
//		: Exp { ',' Exp }
past astFuncRParams(void)
{
	int list = 1;
	past root = newAstNode();
	root->nodeType = "list";
	past func = astExp();
	past head = func;
	while (tok == tok_COMMA)
	{
		list++;
		advance();
		past brother = astExp();
		func->next = brother;
		func = func->next;
	}
	root->value.ivalue = list;
	root->left = head;
	head->nodeType = "parameter";
	head = head->next;
	while (head != NULL)
	{
		head->nodeType = "parameter";
		head = head->next;
	}
	return root;
}

// MulExp
//		: UnaryExp
//		| MulExp ('*' | '/' | '%') UnaryExp
past astMulExp(void)
{

	past l = astUnaryExp();
	while (tok == tok_MUL || tok == tok_DIV || tok == tok_MODULO)
	{
		int oper = tok;
		advance();
		past r = astUnaryExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// AddExp
//		: MulExp
//		| AddExp ('+' | '−') MulExp
past astAddExp(void)
{

	past l = astMulExp();
	while (tok == tok_ADD || tok == tok_SUB)
	{
		int oper = tok;
		advance();
		past r = astMulExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// RelExp
//		: AddExp
//		| RelExp ('<' | '>' | '<=' | '>=') AddExp
past astRelExp(void)
{

	past l = astAddExp();
	while (tok == tok_LESS || tok == tok_GREAT || tok == tok_LESSEQ || tok == tok_GREATEQ)
	{
		int oper = tok;
		advance();
		past r = astRelExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// EqExp
//		: RelExp
//		| EqExp ('==' | '!=') RelExp
past astEqExp(void)
{

	past l = astRelExp();
	while (tok == tok_EQ || tok == tok_NOTEQ)
	{
		int oper = tok;
		advance();
		past r = astRelExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// LAndExp
//		: EqExp
//		| LAndExp '&&' EqExp
past astLAndExp(void)
{

	past l = astEqExp();
	while (tok == tok_AND)
	{
		int oper = tok;
		advance();
		past r = astEqExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// LOrExp
//		: LAndExp
//		| LOrExp '||' LAndExp
past astLOrExp(void)
{

	past l = astLAndExp();
	while (tok == tok_OR)
	{
		int oper = tok;
		advance();
		past r = astLAndExp();
		l = newExpr(oper, l, r, NULL);
	}
	return l;
}

// ConstExp
//		: AddExp
past astConstExp(void)
{
	past a = astAddExp();
	return a;
}
