#define log(format, ...) fprintf(yyout, format, ##__VA_ARGS__)

typedef struct _ast ast;
typedef struct _ast *past;
typedef struct _symtab symtab;
typedef struct _symtab *tab;

struct _ast
{
    char *nodeType;
    int line;
    int ivalue;
    char *evalue;
    past left;
    past right;
    past next;
};
enum Token_T
{
    tok_ID = 256,       // 标识符
    tok_INTEGER = 257,  // 整数
    tok_INT = 258,      // int
    tok_VOID = 259,     // void
    tok_CONST = 260,    // const
    tok_IF = 261,       // if
    tok_ELSE = 262,     // else
    tok_WHILE = 263,    // while
    tok_BREAK = 264,    // break
    tok_CONTINUE = 265, // continue
    tok_RETURN = 266,   // return
    tok_ADD = 267,      // +
    tok_SUB = 268,      // -
    tok_MUL = 269,      // *
    tok_DIV = 270,      // /
    tok_MODULO = 271,   // %
    tok_LESS = 272,     // <
    tok_LESSEQ = 273,   // <=
    tok_GREAT = 274,    // >
    tok_GREATEQ = 275,  // >=
    tok_NOTEQ = 276,    // !=
    tok_EQ = 277,       // ==
    tok_NOT = 278,      // !
    tok_AND = 279,      // &&
    tok_OR = 280,       // ||
    tok_ASSIGN = 281,   // =

    tok_LPAR = 282,      // (
    tok_RPAR = 283,      // )
    tok_LBRACKET = 284,  // {
    tok_RBRACKET = 285,  // }
    tok_LSQUARE = 286,   // [
    tok_RSQUARE = 287,   // ]
    tok_COMMA = 288,     // ,
    tok_SEMICOLON = 289, // ;
    tok_comment = 290
};

extern past astHead;

past checkMalloc();

past newAstNode();
past newList(past list, past node);
past newID(char *evalue);
past newNumber(int ivalue);
past newString(char *evalue);

past newCompUnit(past left, past right);
past newConstDecl(past left, past right);
past newConstDefs(past left, past right);
past newConstDef(past left, past right, past init);
past newConstExps(past left, past right);
past newConstInitVals(past left, past right);
past newConstInitVal(past left);
past newVarDecl(past left);
past newVarDef(int x, past left, past right, past init);
past newVarDefs(past left, past right);
past newInitVals(past left, past right);
past newInitVal(past left);
past newFuncDef(int x, past left, past right);
past newDeclarator(past left, past right);
past newFuncFParams(past left, past right);
past newFuncFParam(int x, past left, past right);
past newBlockItems(past left, past right);
past newBlock(past left);
past newStmt(past left, past right);

past continueStmt();
past breakStmt();
past returnStmt(past expr);
past ifStmt(past cond, past stmt, past elseStmt);
past lvalStmt(past left, past right);
past exprStmt(past expr);
past whileStmt(past cond, past stmt);

past newLval(past left, past right);
past newExps(past left, past right);
past newExpr(int oper, past left, past right);
past newUnaryExp(int op, past left, past right);
past newFuncRParams(past left, past right);

void showAst(past p, int nest);
