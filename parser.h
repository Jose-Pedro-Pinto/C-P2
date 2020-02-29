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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 85 "parser.bison" /* yacc.c:1909  */

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern int yyline;
extern int TYPEval;
extern int OPval;
extern int BOOL_OP_TYPE;
extern char* yytext;
extern FILE* yyin;
extern String_Stack_Holder* StackVar;
extern String_Stack_Holder* StackStr;

extern void yyerror(const char* msg);
Global_Function* root;

#line 63 "parser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAL = 258,
    INT = 259,
    FLOAT = 260,
    DOUBLE = 261,
    PLUS = 262,
    MINUS = 263,
    PROD = 264,
    DIV = 265,
    MOD = 266,
    OP_MP = 267,
    OP_PP = 268,
    OP_BOL = 269,
    FALSE = 270,
    TRUE = 271,
    TYPE = 272,
    COM_END = 273,
    COM_FUNC = 274,
    IF = 275,
    ELSE = 276,
    WHILE = 277,
    EQ = 278,
    VAR = 279,
    SCANF = 280,
    PRINTF = 281,
    BR_OP = 282,
    BR_CL = 283,
    STRING = 284,
    PAR_OP = 285,
    PAR_CL = 286,
    COMMA = 287,
    BOOL_AND = 288,
    BOOL_OR = 289,
    BOOL_OP = 290,
    LESS_THAN = 291,
    MORE_THAN = 292,
    CHECK_EQ = 293,
    LESS_EQ_THAN = 294,
    MORE_EQ_THAN = 295,
    DIFF = 296,
    ELSEIF = 297,
    RETURN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "parser.bison" /* yacc.c:1909  */

  int intValue;
  Expr* exprValue;
  COM* com;
  COM_LIST* comlist;
  Atribution* VarAtr;
  Function* Funct;
  Arg_List* List;
  BoolExprList* BList;
  BoolExpr* Bool_Expr;
  Global_Function* GlobalFunc;

#line 132 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
