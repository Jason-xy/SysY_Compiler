/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lrparser.y" /* yacc.c:339  */


#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

#line 74 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDentifier = 258,
    NUMBER = 259,
    INT = 260,
    VOID = 261,
    CONST = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    BREAK = 266,
    CONTINUE = 267,
    RETURN = 268,
    CMP = 269,
    ASSIGN = 270
  };
#endif
/* Tokens.  */
#define IDentifier 258
#define NUMBER 259
#define INT 260
#define VOID 261
#define CONST 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define BREAK 266
#define CONTINUE 267
#define RETURN 268
#define CMP 269
#define ASSIGN 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "lrparser.y" /* yacc.c:355  */

    int     iValue;
    char*   eValue;
    past    pAst;

#line 150 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,     2,     2,    29,     2,     2,
      22,    23,    27,    24,    17,    25,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    30,    34,    35,    36,    37,    40,    41,
      45,    49,    50,    53,    54,    58,    59,    63,    64,    65,
      69,    70,    74,    77,    78,    81,    82,    83,    84,    88,
      89,    90,    94,    95,    99,   100,   104,   105,   106,   110,
     111,   116,   117,   118,   119,   123,   127,   128,   132,   133,
     137,   138,   139,   140,   141,   142,   143,   144,   148,   149,
     152,   155,   158,   159,   163,   167,   168,   171,   174,   177,
     181,   182,   186,   187,   191,   192,   193,   197,   201,   202,
     203,   204,   205,   206,   211,   212,   217,   218,   219,   220,
     224,   225,   226,   230,   231,   235,   239
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDentifier", "NUMBER", "INT", "VOID",
  "CONST", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "CMP",
  "ASSIGN", "';'", "','", "'['", "']'", "'{'", "'}'", "'('", "')'", "'+'",
  "'-'", "'!'", "'*'", "'/'", "'%'", "$accept", "Pro", "CompUnit", "Decl",
  "ConstDecl", "ConstDefs", "ConstDef", "ConstExps", "ConstInitVal",
  "ConstInitVals", "VarDecl", "VarDefs", "VarDef", "InitVal", "InitVals",
  "FuncDef", "Declarator", "FuncFParams", "FuncFParam", "Block",
  "BlockItems", "BlockItem", "Stmt", "SelectionStat", "ElseStat",
  "LValStat", "ExpressionStat", "IterationStat", "ReturnStat", "BreakStat",
  "ContinueStat", "Exp", "LVal", "Exps", "PrimaryExp", "Number",
  "UnaryExp", "FuncRParams", "MulExp", "AddExp", "EqExp", "ConstExp",
  "Ident", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    59,    44,    91,    93,
     123,   125,    40,    41,    43,    45,    33,    42,    47,    37
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,    31,    31,    37,    50,    70,  -137,  -137,  -137,  -137,
    -137,    51,  -137,    40,    18,    40,    48,    31,  -137,  -137,
    -137,  -137,    31,   131,  -137,   179,   219,     8,    58,  -137,
      66,  -137,    17,  -137,    44,  -137,    31,    56,    62,    47,
      71,   190,  -137,   219,   219,   219,   219,  -137,  -137,    89,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,    73,
      75,  -137,  -137,  -137,   121,  -137,    26,   103,  -137,  -137,
    -137,  -137,    76,    31,  -137,     5,  -137,   179,  -137,    31,
     204,    83,   219,   219,  -137,  -137,  -137,    87,    81,  -137,
    -137,  -137,  -137,  -137,  -137,   219,   219,   219,   219,   219,
     219,   219,   214,  -137,  -137,  -137,    32,    90,    94,   113,
    -137,  -137,  -137,   166,  -137,  -137,   204,  -137,     6,     7,
    -137,  -137,   106,  -137,  -137,  -137,  -137,  -137,   111,  -137,
    -137,    22,   179,  -137,  -137,   228,  -137,  -137,  -137,  -137,
      35,  -137,   219,   155,   155,  -137,   114,   219,  -137,  -137,
     114,   204,  -137,  -137,   124,  -137,  -137,  -137,  -137,  -137,
     155,  -137,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     2,     6,     8,     9,     7,
      96,     0,    23,     0,    25,     0,    38,     0,     1,     4,
       5,    22,     0,     0,    34,     0,     0,     0,    27,    35,
       0,    11,     0,    24,    25,    77,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,    48,    51,     0,
      46,    49,    54,    50,    52,    53,    55,    56,    57,     0,
      75,    78,    76,    86,    90,    69,    70,     0,    26,    29,
      75,    95,     0,     0,    37,     0,    39,     0,    10,     0,
       0,     0,     0,     0,    67,    68,    66,     0,     0,    81,
      82,    83,    45,    47,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    30,    32,     0,    15,    41,     0,
      36,    28,    12,     0,    13,    17,     0,    93,     0,     0,
      65,    74,     0,    91,    92,    87,    88,    89,     0,    79,
      84,     0,     0,    31,    16,     0,    43,    40,    18,    20,
       0,    14,     0,     0,     0,    61,    72,     0,    80,    33,
      42,     0,    19,    94,    59,    64,    73,    85,    44,    21,
       0,    58,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,    41,  -137,  -137,    61,   -26,   -97,  -137,
    -137,  -137,   130,   -63,  -137,   149,   158,  -137,    52,     2,
    -137,   115,  -136,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   -16,   -23,  -103,  -137,  -137,   -34,  -137,  -137,   -25,
      79,   146,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    47,     7,    30,    31,    28,   114,   140,
       8,    11,    12,    68,   106,     9,    13,    75,    76,    48,
      49,    50,    51,    52,   161,    53,    54,    55,    56,    57,
      58,    59,    70,   103,    61,    62,    63,   131,    64,    65,
     118,   115,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    71,    14,    16,   105,   136,    81,   154,   155,    69,
      89,    90,    91,    73,   111,    24,   139,    29,    32,   141,
     142,   142,   109,    34,   162,    87,    60,    88,   110,   143,
     144,    74,    80,    25,    10,    26,    26,    34,   -38,   147,
      27,     6,    17,   156,   101,   148,    19,   158,   102,   132,
      18,    69,   151,   133,   159,    71,   152,   117,   117,    25,
      23,    69,    26,    84,   125,   126,   127,    21,    22,   149,
      27,   123,   124,    77,   108,     1,     2,     3,    82,   122,
      32,   134,    78,    79,    83,   128,   130,    85,    71,    94,
      95,    71,    10,    35,    36,   107,     3,    37,   116,    38,
      39,    40,    41,   120,   121,    42,    10,    35,    26,    23,
      92,    43,   135,    44,    45,    46,    69,   153,    73,   128,
      60,    60,   145,    67,   104,    43,    71,    44,    45,    46,
     146,   157,   101,   160,    10,    35,    36,    60,     3,    37,
     112,    38,    39,    40,    41,    96,    97,    42,    98,    99,
     100,    23,    33,    43,    20,    44,    45,    46,    10,    35,
      15,   137,   119,    37,    93,    38,    39,    40,    41,    10,
      35,    42,    72,     0,     0,    23,     0,    43,     0,    44,
      45,    46,    10,    35,     0,     0,   113,   138,    43,     0,
      44,    45,    46,    10,    35,     0,     0,     0,     0,    67,
       0,    43,     0,    44,    45,    46,    86,    10,    35,     0,
       0,     0,    43,     0,    44,    45,    46,    10,    35,     0,
       0,     0,    10,    35,   113,     0,    43,     0,    44,    45,
      46,    10,    35,     0,     0,     0,    43,   129,    44,    45,
      46,    43,     0,    44,    45,    46,     0,   150,     0,     0,
      43,     0,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      23,    26,     1,     2,    67,   108,    32,   143,   144,    25,
      44,    45,    46,     5,    77,    13,   113,    15,    17,   116,
      14,    14,    17,    22,   160,    41,    49,    43,    23,    23,
      23,    23,    15,    15,     3,    18,    18,    36,    20,    17,
      22,     0,     5,   146,    18,    23,     5,   150,    22,    17,
       0,    67,    17,    21,   151,    80,    21,    82,    83,    15,
      20,    77,    18,    16,    98,    99,   100,    16,    17,   132,
      22,    96,    97,    15,    73,     5,     6,     7,    22,    95,
      79,   107,    16,    17,    22,   101,   102,    16,   113,    16,
      15,   116,     3,     4,     5,    19,     7,     8,    15,    10,
      11,    12,    13,    16,    23,    16,     3,     4,    18,    20,
      21,    22,    18,    24,    25,    26,   132,   142,     5,   135,
     143,   144,    16,    20,    21,    22,   151,    24,    25,    26,
      19,   147,    18,     9,     3,     4,     5,   160,     7,     8,
      79,    10,    11,    12,    13,    24,    25,    16,    27,    28,
      29,    20,    22,    22,     5,    24,    25,    26,     3,     4,
       2,   109,    83,     8,    49,    10,    11,    12,    13,     3,
       4,    16,    26,    -1,    -1,    20,    -1,    22,    -1,    24,
      25,    26,     3,     4,    -1,    -1,    20,    21,    22,    -1,
      24,    25,    26,     3,     4,    -1,    -1,    -1,    -1,    20,
      -1,    22,    -1,    24,    25,    26,    16,     3,     4,    -1,
      -1,    -1,    22,    -1,    24,    25,    26,     3,     4,    -1,
      -1,    -1,     3,     4,    20,    -1,    22,    -1,    24,    25,
      26,     3,     4,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    22,    -1,    24,    25,    26,    -1,    19,    -1,    -1,
      22,    -1,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    31,    32,    33,    34,    40,    45,
       3,    41,    42,    46,    72,    46,    72,     5,     0,    33,
      45,    16,    17,    20,    49,    15,    18,    22,    37,    49,
      35,    36,    72,    42,    72,     4,     5,     8,    10,    11,
      12,    13,    16,    22,    24,    25,    26,    33,    49,    50,
      51,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    64,    65,    66,    68,    69,    72,    20,    43,    61,
      62,    69,    71,     5,    23,    47,    48,    15,    16,    17,
      15,    37,    22,    22,    16,    16,    16,    61,    61,    66,
      66,    66,    21,    51,    16,    15,    24,    25,    27,    28,
      29,    18,    22,    63,    21,    43,    44,    19,    72,    17,
      23,    43,    36,    20,    38,    71,    15,    69,    70,    70,
      16,    23,    61,    69,    69,    66,    66,    66,    61,    23,
      61,    67,    17,    21,    37,    18,    63,    48,    21,    38,
      39,    38,    14,    23,    23,    16,    19,    17,    23,    43,
      19,    17,    21,    69,    52,    52,    63,    61,    63,    38,
       9,    54,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    33,    33,
      34,    35,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    55,    56,    56,    57,    58,    58,    59,    60,    61,
      62,    62,    63,    63,    64,    64,    64,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     1,     1,
       4,     1,     3,     3,     4,     3,     4,     1,     2,     3,
       1,     3,     3,     1,     3,     1,     3,     2,     4,     1,
       2,     3,     1,     3,     3,     3,     4,     3,     1,     1,
       3,     2,     4,     3,     5,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     5,
       2,     4,     1,     2,     5,     3,     2,     2,     2,     1,
       1,     2,     3,     4,     3,     1,     1,     1,     1,     3,
       4,     2,     2,     2,     1,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 29 "lrparser.y" /* yacc.c:1646  */
    { astHead = (yyvsp[0].pAst); }
#line 1379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 30 "lrparser.y" /* yacc.c:1646  */
    { printf("empty\n"); }
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 34 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newCompUnit((yyvsp[0].pAst), (yyvsp[-1].pAst)); }
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 35 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newCompUnit((yyvsp[0].pAst), (yyvsp[-1].pAst)); }
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 36 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newCompUnit((yyvsp[0].pAst), NULL); }
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 37 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newCompUnit((yyvsp[0].pAst), NULL); }
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 40 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 41 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 45 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[-1].pAst); }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 49 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstDefs((yyvsp[0].pAst),NULL); }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 50 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstDefs((yyvsp[0].pAst),(yyvsp[-2].pAst)); }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 53 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstDef((yyvsp[-2].pAst), NULL, (yyvsp[0].pAst)); }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 54 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstDef((yyvsp[-3].pAst), (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstExps((yyvsp[-1].pAst), NULL); }
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 59 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstExps((yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstInitVal((yyvsp[0].pAst)); }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 64 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstInitVal(NULL); }
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 65 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstInitVal((yyvsp[-1].pAst)); }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 69 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstInitVals((yyvsp[0].pAst),NULL); }
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 70 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newConstInitVals((yyvsp[0].pAst),(yyvsp[-2].pAst)); }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 74 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[-1].pAst); }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 77 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDefs((yyvsp[0].pAst),NULL); }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDefs((yyvsp[0].pAst),(yyvsp[-2].pAst)); }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 81 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDef(0, (yyvsp[0].pAst), NULL, NULL); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDef(1, (yyvsp[-2].pAst), NULL, (yyvsp[0].pAst)); }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDef(2, (yyvsp[-1].pAst), (yyvsp[0].pAst), NULL); }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newVarDef(3, (yyvsp[-3].pAst), (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 88 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newInitVal((yyvsp[0].pAst)); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 89 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = NULL; }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 90 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newInitVal((yyvsp[-1].pAst)); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 94 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newInitVals((yyvsp[0].pAst),NULL);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newInitVals((yyvsp[0].pAst),(yyvsp[-2].pAst));}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 99 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncDef(0, (yyvsp[-1].pAst), (yyvsp[0].pAst)); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 100 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncDef(1, (yyvsp[-1].pAst), (yyvsp[0].pAst)); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newDeclarator((yyvsp[-3].pAst), (yyvsp[-1].pAst)); }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 105 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newDeclarator((yyvsp[-2].pAst), NULL); }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newDeclarator((yyvsp[0].pAst),NULL); }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParams((yyvsp[0].pAst), NULL); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParams((yyvsp[0].pAst), (yyvsp[-2].pAst)); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 116 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParam(0, (yyvsp[0].pAst), NULL); }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParam(1, (yyvsp[-2].pAst), NULL); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 118 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParam(2, (yyvsp[-1].pAst), (yyvsp[0].pAst)); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 119 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncFParam(3, (yyvsp[-3].pAst), (yyvsp[0].pAst)); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 123 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newBlock((yyvsp[-1].pAst)); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 127 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newBlockItems((yyvsp[0].pAst), NULL); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 128 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newBlockItems((yyvsp[0].pAst), (yyvsp[-1].pAst)); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 140 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 141 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 142 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 143 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 144 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = ifStmt((yyvsp[-3].pAst), (yyvsp[-1].pAst), (yyvsp[0].pAst)); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = ifStmt((yyvsp[-2].pAst), (yyvsp[0].pAst), NULL); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 152 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 155 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = lvalStmt((yyvsp[-3].pAst),(yyvsp[-1].pAst)); }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 158 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = exprStmt(NULL); }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 159 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = exprStmt((yyvsp[-1].pAst)); }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 163 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = whileStmt((yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 167 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = returnStmt((yyvsp[-1].pAst)); }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 168 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = returnStmt(NULL); }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 171 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = breakStmt(); }
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 174 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = continueStmt(); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 177 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 181 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newLval((yyvsp[0].pAst), NULL); }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 182 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newLval((yyvsp[-1].pAst), (yyvsp[0].pAst)); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 186 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExps((yyvsp[-1].pAst), NULL); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 187 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExps((yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 191 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[-1].pAst); }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 192 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 193 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 197 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newNumber((yyvsp[0].iValue)); }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 201 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 202 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newUnaryExp(-1, (yyvsp[-2].pAst), NULL); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 203 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newUnaryExp(-1, (yyvsp[-3].pAst), (yyvsp[-1].pAst)); }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 204 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newUnaryExp('+', (yyvsp[0].pAst), NULL); }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 205 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newUnaryExp('-', (yyvsp[0].pAst), NULL); }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 206 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newUnaryExp('!', (yyvsp[0].pAst), NULL); }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 211 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncRParams((yyvsp[0].pAst), NULL); }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 212 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newFuncRParams((yyvsp[0].pAst), (yyvsp[-2].pAst)); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 217 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 218 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr('*', (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 219 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr('/', (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 220 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr('%', (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 224 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 225 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr('+', (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 226 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr('-', (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 230 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 231 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newExpr((yyvsp[-1].iValue), (yyvsp[-2].pAst), (yyvsp[0].pAst)); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 235 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = (yyvsp[0].pAst); }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 239 "lrparser.y" /* yacc.c:1646  */
    { (yyval.pAst) = newString((yyvsp[0].eValue)); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1947 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 242 "lrparser.y" /* yacc.c:1906  */
