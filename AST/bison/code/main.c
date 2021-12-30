#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#define BAD_OUTPUT 0
// #define GLOVAL_LOG_LEVEL 3

extern FILE *yyin;
extern FILE *yyout;
extern int yyparse();

void yyerror(char const *msg, ...)
{
    va_list va_args;
    va_start(va_args, msg);
    if (yyout)
    {
        fprintf(yyout, msg, va_args);
        // fprintf(stdout, "\t\t\t\terr on");
        return;
    }
    fprintf(yyout, msg, va_args);
    // fprintf(stdout, "\t\t\t\terr on");
    va_end(va_args);
}

int input_switcher(int argc, char **argv)
{
    switch (argc)
    {
    case 2:
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            exit(-1);
        }
        //printf("use data from file:%s\n", argv[1]);
        break;
    case 3:
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            exit(-1);
        }
        if (!(yyout = fopen(argv[2], "a")))
        {
            perror(argv[2]);
            printf("argv[2]:bad address\noutput to stdout\n");
            return BAD_OUTPUT;
        }
        // printf("use data from file:%s\n", argv[1]);
        //printf("output data to file:%s\n", argv[2]);
        break;
    default:
        //printf("use data from stdin\n");
        break;
    }
}

void main(int argc, char **argv)
{

    if (!input_switcher(argc, argv))
        yyout = stdout;
    yyparse();
    log("%s\n", argv[1]);
    log("Program\n");
    showAst(astHead, 0);
    return;
}
