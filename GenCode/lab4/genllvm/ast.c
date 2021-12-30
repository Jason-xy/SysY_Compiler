/*
 * ast.c
 *
 *  Created on: 2014年10月23日
 *      Author: erqiang
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

int lineno = 0;

void showAst(past node, int nest)
{
	if(node == NULL)
		return;

	int i = 0;
	for(i = 0; i < nest; i ++)
		printf("  ");
	if(strcmp(node->nodeType, "intValue") == 0)
		printf("%s %d\n", node->nodeType, node->ivalue);
	else if(strcmp(node->nodeType, "expr") == 0)
		printf("%s '%c'\n", node->nodeType, (char)node->ivalue);
	showAst(node->left, nest+1);
	showAst(node->right, nest+1);

}

past newAstNode()
{
	past node = malloc(sizeof(ast));
	if(node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	node->lineno = lineno;
	return node;
}

past newList(past list, past node)
{
	if(list != NULL)
	{
		//add node to the tail of list
		listTail(list)->next = node;

		//make tail to point to the last element of list
		listTail(list) = node;
		list->ivalue += 1;
		return list;
	}

	list = newAstNode();
	list->nodeType = "list";
	list->next = node;
	list->ivalue = 1;

	listHead(list) = node;
	listTail(list) = node;

	return list;
}



past newNum(int value)
{
	past var = newAstNode();
	var->nodeType = "intValue";
	var->ivalue = value;
	return var;
}
past newExpr(int oper, past left,past right)
{
	past var = newAstNode();
	var->nodeType = "expr";
	var->ivalue = oper;
	var->left = left;
	var->right = right;
	return var;
}

