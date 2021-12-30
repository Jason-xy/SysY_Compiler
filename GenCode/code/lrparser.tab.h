/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_LRPARSER_TAB_H_INCLUDED
# define YY_YY_LRPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_VOID = 259,
    ASSIGN = 260,
    SEMICOLON = 261,
    COMMA = 262,
    LPAREN = 263,
    RPAREN = 264,
    LBRACE = 265,
    RBRACE = 266,
    LBRACKET = 267,
    RBRACKET = 268,
    CONST = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    RETURN = 273,
    BREAK = 274,
    CONTINUE = 275,
    EQUAL = 276,
    NOTEQUAL = 277,
    GRATEREQUAL = 278,
    LESSEQUAL = 279,
    GRATER = 280,
    LESS = 281,
    ADD = 282,
    SUB = 283,
    MUL = 284,
    DIV = 285,
    MOD = 286,
    AND = 287,
    OR = 288,
    NOT = 289,
    IDENTIFIER = 290,
    CONSTANT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_TAB_H_INCLUDED  */
