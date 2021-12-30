#include <stdio.h>
#include "lrparser.tab.h"
#include "tree.h"
#include "genllvm.h"

Ast *g_root;
extern FILE *yyin;
extern FILE *fp_error;
extern FILE *out;
int yyparse();

int main(int argc, char *argv[])
{
    g_root = createNode(0, NT_ROOT, "root");
    yyin = fopen(argv[1], "r");
    fp_error = fopen("error.txt", "w");
    FILE *ast = fopen("ast.txt", "w");
    out = fopen("output.txt", "w");

    yyparse();
    printAst(g_root, ast);
    fclose(ast);
    
    genRoot(g_root);

    fclose(yyin);
    fclose(fp_error);
    fclose(out);
    return 0;
}