%{
    #include <string.h>
    #include "lrparser.tab.h"
    #include "tree.h"

    char msg[MAX_MESSAGE_LEN];
    FILE *fp_error;
    int lineno = 1;
    int errors = 0;
%}

LINECOMMENT \/\/[^\n]*
BLOCKCOMMENT_START \/\*+
BLOCKCOMMENT_CONTENT ([^\*\n]*|\*+)
BLOCKCOMMENT_EOL \n
BLOCKCOMMENT_END \*+\/

EOL (\r\n|\r|\n)
SPACE [ \t]+

BINNUMBER 0[Bb][01]+
OCTNUMBER 0[0-7]+
DECNUMBER -?[0-9]+
HEXNUMBER 0[Xx][A-Fa-f0-9]+
STRING \"[^\"]*\"

IDENTIFIER [A-Za-z_][A-Za-z0-9_]*

%start BLOCKCOMMENT

%%

{BLOCKCOMMENT_START} {BEGIN BLOCKCOMMENT;}
<BLOCKCOMMENT>{BLOCKCOMMENT_CONTENT} { /* do nothing */ }
<BLOCKCOMMENT>{BLOCKCOMMENT_EOL} {lineno++;}
<BLOCKCOMMENT>{BLOCKCOMMENT_END} {BEGIN INITIAL;}

{LINECOMMENT} { /* do nothing */ }

{EOL} { lineno++; }

{SPACE} { /* do nothing */ }

{IDENTIFIER} {
    if (strcmp(yytext, "int") == 0)
    {
        strcpy(msg, "int");
        return T_INT;
    }
    if (strcmp(yytext, "void") == 0)
    {
        strcpy(msg, "void");
        return T_VOID;
    }
    if (strcmp(yytext, "if") == 0)
        return IF;
    if (strcmp(yytext, "else") == 0)
        return ELSE;
    if (strcmp(yytext, "while") == 0)
        return WHILE;
    if (strcmp(yytext, "const") == 0)
        return CONST;
    if (strcmp(yytext, "continue") == 0)
        return CONTINUE;
    if (strcmp(yytext, "break") == 0)
        return BREAK;
    if (strcmp(yytext, "return") == 0) 
        return RETURN;
    strcpy(msg, yytext);
    return IDENTIFIER;
}

"(" { return LPAREN; }
")" { return RPAREN;}
"[" { return LBRACKET; }
"]" { return RBRACKET; }
"{" { return LBRACE; }
"}" { return RBRACE; }
"," { return COMMA; }
";" { return SEMICOLON; }

"==" { return EQUAL; }
">=" { return GRATEREQUAL; }
"<=" { return LESSEQUAL; }
"!=" { return NOTEQUAL; }
"=" { return ASSIGN; }
">" { return GRATER; }
"<" { return LESS; }

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"%" { return MOD; }

"&&" { return AND; }
"||" { return OR; }
"!" { return NOT; }

{BINNUMBER} {
    int value = strtol(yytext + 2, NULL, 2);
    bzero(msg, sizeof(msg));
    sprintf(msg, "%d", value);
    return CONSTANT; 
}
{OCTNUMBER} {
    int value = strtol(yytext + 2, NULL, 8);
    bzero(msg, sizeof(msg));
    sprintf(msg, "%d", value);
    return CONSTANT; 
}
{DECNUMBER} {
    int value = atoi(yytext);
    bzero(msg, sizeof(msg));
    sprintf(msg, "%d", value);
    return CONSTANT; 
}
{HEXNUMBER} {
    int value = strtol(yytext + 2, NULL, 16);
    bzero(msg, sizeof(msg));
    sprintf(msg, "%d", value);
    return CONSTANT; 
}

. {
    fprintf(fp_error, "error: line %d: Illegal character '%s'", lineno, yytext);
    errors++;
}

%%

int yywrap()
{
    return 1;
}