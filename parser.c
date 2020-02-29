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

#line 67 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
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
#line 85 "parser.bison" /* yacc.c:355  */

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

#line 116 "parser.c" /* yacc.c:355  */

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
#line 56 "parser.bison" /* yacc.c:355  */

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

#line 185 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   107,   107,   110,   112,   113,   116,   117,   118,   121,
     122,   123,   124,   126,   127,   128,   129,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   143,   144,   145,
     146,   147,   148,   150,   151,   152,   153,   154,   155,   156,
     157,   160,   161,   162,   165,   166,   167,   168,   169,   170,
     171,   175,   176,   177,   178,   179,   180,   181,   182
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAL", "INT", "FLOAT", "DOUBLE", "PLUS",
  "MINUS", "PROD", "DIV", "MOD", "OP_MP", "OP_PP", "OP_BOL", "FALSE",
  "TRUE", "TYPE", "COM_END", "COM_FUNC", "IF", "ELSE", "WHILE", "EQ",
  "VAR", "SCANF", "PRINTF", "BR_OP", "BR_CL", "STRING", "PAR_OP", "PAR_CL",
  "COMMA", "BOOL_AND", "BOOL_OR", "BOOL_OP", "LESS_THAN", "MORE_THAN",
  "CHECK_EQ", "LESS_EQ_THAN", "MORE_EQ_THAN", "DIFF", "ELSEIF", "RETURN",
  "$accept", "program", "G_Function", "com_list", "com", "initV",
  "initV_Comp", "call_Atrib", "call_Func", "else_part", "ARGLIST",
  "bool_list", "bool_expr", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,   -19,     4,   -60,     6,   -60,    33,   -11,   145,     1,
      45,    50,    71,    66,    69,    18,    74,   145,   -60,   -60,
     -60,    92,    90,    90,    18,    52,    52,   -60,   -60,    18,
     197,   -60,   -60,   -60,    18,    80,   -60,   -60,    90,    78,
      -5,    81,    82,   202,    87,    98,   102,   103,    24,   110,
     183,    18,    18,    18,    18,    18,   -60,   165,    99,   114,
     -13,    76,   101,    90,    90,    90,    90,   112,   -60,    52,
      52,    -1,    52,    52,    94,   -60,    36,    36,   -60,   -60,
     -60,   -60,    80,   -60,    18,    80,   -60,   -60,   145,   -15,
     -60,   -60,   107,    81,   107,    81,   145,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   171,   -60,   124,   123,   127,
     -60,   125,   -60,    80,   -15,   145,   -60,    90,   -60,   -60,
     -60,   135,   133,   -60,   134,   145,   -15,   140,   -60,   -15,
     -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,    51,    52,     0,
       0,     3,     4,    10,     0,     0,    45,    44,     0,     0,
      41,     0,     0,     0,    38,    36,     0,    40,    34,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    58,    53,    54,    55,    56,
      57,     9,     0,    13,     0,     0,    11,    50,     0,    20,
      42,    43,    49,    47,    48,    46,     0,    21,    37,    35,
      18,    39,    33,    19,    12,     0,    15,     0,     0,     0,
      22,     0,    14,     0,    23,     0,    27,     0,    25,    16,
      24,     0,     0,    28,     0,     0,    29,     0,    31,    30,
      32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -17,   -55,   -60,   -59,   -60,   -12,    70,
      -7,   -20,    35,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    16,    17,    18,    59,    19,    20,   110,
      46,    47,    40,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    30,    39,    42,     5,     4,   108,    89,    41,    41,
      43,     1,    97,    45,    45,    50,     8,   100,    87,    49,
      57,    27,    65,   104,    61,    21,   106,   109,    63,    64,
      65,    51,    52,    53,    54,    55,     6,    76,    77,    78,
      79,    80,    28,    90,    91,    53,    54,    55,    29,    41,
      41,    93,    95,   116,   119,    27,    73,    45,    45,    66,
      45,    45,    98,    99,     7,   101,   102,    36,    37,   126,
     105,   107,    10,    60,    11,    22,    28,    13,    14,   111,
      23,    44,    38,    51,    52,    53,    54,    55,    51,    52,
      53,    54,    55,    27,    24,    15,    25,   122,   121,    26,
      92,    94,    31,    41,    58,    36,    37,    75,   127,    62,
      33,    66,   103,    67,    28,    34,    66,    83,     9,    69,
      38,    10,    84,    11,    35,    12,    13,    14,    88,     9,
      70,    85,    10,    71,    11,    72,    12,    13,    14,    96,
       9,    74,    65,    10,    15,    11,    86,    12,    13,    14,
     115,     9,   114,   118,    10,    15,    11,   117,    12,    13,
      14,   125,     9,   123,   124,    10,    15,    11,   129,    12,
      13,    14,    51,    52,    53,    54,    55,    15,    51,    52,
      53,    54,    55,    81,   120,     0,     0,     0,    15,   112,
      51,    52,    53,    54,    55,     0,   128,    82,     0,   130,
       0,     0,     0,   113,    51,    52,    53,    54,    55,    51,
      52,    53,    54,    55,    75,    56,     0,     0,     0,     0,
      68
};

static const yytype_int16 yycheck[] =
{
      17,    15,    22,    23,     0,    24,    21,    62,    22,    23,
      24,    17,    67,    25,    26,    29,    27,    18,    31,    26,
      34,     3,    35,    82,    38,    24,    85,    42,    33,    34,
      35,     7,     8,     9,    10,    11,    30,    51,    52,    53,
      54,    55,    24,    63,    64,     9,    10,    11,    30,    63,
      64,    65,    66,   108,   113,     3,    32,    69,    70,    35,
      72,    73,    69,    70,    31,    72,    73,    15,    16,   124,
      84,    88,    20,    38,    22,    30,    24,    25,    26,    96,
      30,    29,    30,     7,     8,     9,    10,    11,     7,     8,
       9,    10,    11,     3,    23,    43,    30,   117,   115,    30,
      65,    66,    28,   117,    24,    15,    16,    31,   125,    31,
      18,    35,    18,    31,    24,    23,    35,    18,    17,    32,
      30,    20,    23,    22,    32,    24,    25,    26,    27,    17,
      32,    32,    20,    31,    22,    32,    24,    25,    26,    27,
      17,    31,    35,    20,    43,    22,    32,    24,    25,    26,
      27,    17,    28,    28,    20,    43,    22,    30,    24,    25,
      26,    27,    17,    28,    31,    20,    43,    22,    28,    24,
      25,    26,     7,     8,     9,    10,    11,    43,     7,     8,
       9,    10,    11,    18,   114,    -1,    -1,    -1,    43,    18,
       7,     8,     9,    10,    11,    -1,   126,    32,    -1,   129,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,     7,
       8,     9,    10,    11,    31,    18,    -1,    -1,    -1,    -1,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    45,    46,    24,     0,    30,    31,    27,    17,
      20,    22,    24,    25,    26,    43,    47,    48,    49,    51,
      52,    24,    30,    30,    23,    30,    30,     3,    24,    30,
      57,    28,    47,    18,    23,    32,    15,    16,    30,    55,
      56,    57,    55,    57,    29,    52,    54,    55,    57,    54,
      57,     7,     8,     9,    10,    11,    18,    57,    24,    50,
      56,    57,    31,    33,    34,    35,    35,    31,    18,    32,
      32,    31,    32,    32,    31,    31,    57,    57,    57,    57,
      57,    18,    32,    18,    23,    32,    32,    31,    27,    48,
      55,    55,    56,    57,    56,    57,    27,    48,    54,    54,
      18,    54,    54,    18,    50,    57,    50,    47,    21,    42,
      53,    47,    18,    32,    28,    27,    48,    30,    28,    50,
      53,    47,    55,    28,    31,    27,    48,    47,    53,    28,
      53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    47,    47,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    50,    50,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     2,     1,     1,     1,     1,     5,
       3,     5,     6,     2,     4,     3,     5,     4,     5,     5,
       5,     5,     6,     7,     8,     7,     3,     2,     4,     5,
       7,     6,     8,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3
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
#line 107 "parser.bison" /* yacc.c:1646  */
    { root = (yyvsp[0].GlobalFunc);}
#line 1382 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.bison" /* yacc.c:1646  */
    { (yyval.GlobalFunc) = create_Global_Function(TYPEval,pop_Stack(StackVar), (yyvsp[-1].comlist));}
#line 1388 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "parser.bison" /* yacc.c:1646  */
    { (yyval.comlist) = create_COM_LIST((yyvsp[-1].com),(yyvsp[0].comlist)); }
#line 1394 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.bison" /* yacc.c:1646  */
    { (yyval.comlist) = create_COM_LIST((yyvsp[0].com), NULL); }
#line 1400 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "parser.bison" /* yacc.c:1646  */
    { (yyval.com) = create_COM( INIT, (yyvsp[0].VarAtr), NULL); }
#line 1406 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "parser.bison" /* yacc.c:1646  */
    { (yyval.com) = create_COM(ATRIB, (yyvsp[0].VarAtr),NULL);}
#line 1412 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "parser.bison" /* yacc.c:1646  */
    {(yyval.com) = create_COM(FUNC, NULL,(yyvsp[0].Funct));}
#line 1418 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, NULL, (yyvsp[-1].exprValue)); }
#line 1424 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,NULL, NULL); }
#line 1430 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,(yyvsp[-1].VarAtr), NULL); }
#line 1436 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, (yyvsp[0].VarAtr), (yyvsp[-2].exprValue)); }
#line 1442 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,NULL, NULL); }
#line 1448 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, NULL, (yyvsp[-1].exprValue)); }
#line 1454 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,(yyvsp[0].VarAtr), NULL); }
#line 1460 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "parser.bison" /* yacc.c:1646  */
    { (yyval.VarAtr) = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, (yyvsp[0].VarAtr), (yyvsp[-2].exprValue)); }
#line 1466 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 131 "parser.bison" /* yacc.c:1646  */
    {(yyval.VarAtr) = create_Atribution(pop_Stack(StackVar),0, yyline,NULL, (yyvsp[-1].exprValue)); }
#line 1472 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "parser.bison" /* yacc.c:1646  */
    {(yyval.Funct) = create_Function("scanf", (yyvsp[-2].List), NULL,NULL);}
#line 1478 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "parser.bison" /* yacc.c:1646  */
    {(yyval.Funct) = create_Function("printf", (yyvsp[-2].List), NULL,NULL);}
#line 1484 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("if",create_ArgList(NULL,NULL,NULL, (yyvsp[-2].BList),NULL),create_COM_LIST((yyvsp[0].com),NULL),NULL);}
#line 1490 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("while",create_ArgList(NULL,NULL,NULL, (yyvsp[-2].BList),NULL),create_COM_LIST((yyvsp[0].com),NULL),NULL);}
#line 1496 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 137 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("if",create_ArgList(NULL,NULL,NULL, (yyvsp[-3].BList),NULL),create_COM_LIST((yyvsp[-1].com),NULL),(yyvsp[0].Funct));}
#line 1502 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("if",create_ArgList(NULL,NULL,NULL, (yyvsp[-4].BList),NULL),(yyvsp[-1].comlist),NULL);}
#line 1508 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("if",create_ArgList(NULL,NULL,NULL, (yyvsp[-5].BList),NULL),(yyvsp[-2].comlist),(yyvsp[0].Funct));}
#line 1514 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("while",create_ArgList(NULL,NULL,NULL, (yyvsp[-4].BList),NULL),(yyvsp[-1].comlist),NULL);}
#line 1520 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("return",create_ArgList((yyvsp[-1].exprValue),NULL,NULL, NULL,NULL),NULL,NULL);}
#line 1526 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 143 "parser.bison" /* yacc.c:1646  */
    {(yyval.Funct) = create_Function("else",NULL,create_COM_LIST((yyvsp[0].com),NULL),NULL);}
#line 1532 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 144 "parser.bison" /* yacc.c:1646  */
    {(yyval.Funct) = create_Function("else",NULL,(yyvsp[-1].comlist),NULL);}
#line 1538 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("else if",create_ArgList(NULL,NULL,NULL, (yyvsp[-2].BList),NULL),create_COM_LIST((yyvsp[0].com),NULL),NULL);}
#line 1544 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("else if",create_ArgList(NULL,NULL,NULL, (yyvsp[-4].BList),NULL),(yyvsp[-1].comlist),NULL);}
#line 1550 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("else if",create_ArgList(NULL,NULL,NULL, (yyvsp[-3].BList),NULL),create_COM_LIST((yyvsp[-1].com),NULL),(yyvsp[0].Funct));}
#line 1556 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 148 "parser.bison" /* yacc.c:1646  */
    { (yyval.Funct) = create_Function("else if",create_ArgList(NULL,NULL,NULL, (yyvsp[-5].BList),NULL),(yyvsp[-2].comlist),(yyvsp[0].Funct));}
#line 1562 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 150 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList((yyvsp[-2].exprValue),NULL,NULL,NULL,(yyvsp[0].List));}
#line 1568 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 151 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList((yyvsp[0].exprValue),NULL,NULL,NULL,NULL);}
#line 1574 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 152 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,(yyvsp[-2].Funct),NULL,NULL,(yyvsp[0].List));}
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 153 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,(yyvsp[0].Funct),NULL,NULL,NULL);}
#line 1586 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 154 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,NULL,pop_Stack(StackStr),NULL,(yyvsp[0].List));}
#line 1592 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 155 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,NULL,pop_Stack(StackStr),NULL,NULL);}
#line 1598 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 156 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,NULL,NULL,(yyvsp[-2].BList),(yyvsp[0].List));}
#line 1604 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 157 "parser.bison" /* yacc.c:1646  */
    {(yyval.List) = create_ArgList(NULL,NULL,NULL,(yyvsp[0].BList),NULL);}
#line 1610 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 160 "parser.bison" /* yacc.c:1646  */
    {(yyval.BList) = ast_boolExprlist((yyvsp[0].Bool_Expr),0,NULL);}
#line 1616 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 161 "parser.bison" /* yacc.c:1646  */
    {(yyval.BList) = ast_boolExprlist((yyvsp[-2].Bool_Expr),BOOL_AND,(yyvsp[0].BList));}
#line 1622 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 162 "parser.bison" /* yacc.c:1646  */
    {(yyval.BList) = ast_boolExprlist((yyvsp[-2].Bool_Expr),BOOL_OR,(yyvsp[0].BList));}
#line 1628 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 165 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprInt(1);}
#line 1634 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 166 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprInt(0);}
#line 1640 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 167 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprBool(BOOL_OP_TYPE, NULL,NULL,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1646 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 168 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprBool(BOOL_OP_TYPE,(yyvsp[-2].Bool_Expr),NULL,NULL,(yyvsp[0].exprValue));}
#line 1652 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 169 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprBool(BOOL_OP_TYPE,NULL,(yyvsp[0].Bool_Expr),(yyvsp[-2].exprValue),NULL);}
#line 1658 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 170 "parser.bison" /* yacc.c:1646  */
    { (yyval.Bool_Expr) = ast_boolexprBool(BOOL_OP_TYPE,(yyvsp[-2].Bool_Expr),(yyvsp[0].Bool_Expr),NULL,NULL);}
#line 1664 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 171 "parser.bison" /* yacc.c:1646  */
    {(yyval.Bool_Expr) = (yyvsp[-1].Bool_Expr);}
#line 1670 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 175 "parser.bison" /* yacc.c:1646  */
    {(yyval.exprValue) = ast_integer((yyvsp[0].intValue));}
#line 1676 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 176 "parser.bison" /* yacc.c:1646  */
    {(yyval.exprValue) = ast_variable(pop_Stack(StackVar));}
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 177 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = ast_operation(PLUS,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1688 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 178 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = ast_operation(MINUS,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1694 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 179 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = ast_operation(PROD,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1700 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 180 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = ast_operation(DIV,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1706 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 181 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = ast_operation(MOD,(yyvsp[-2].exprValue),(yyvsp[0].exprValue));}
#line 1712 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 182 "parser.bison" /* yacc.c:1646  */
    { (yyval.exprValue) = (yyvsp[-1].exprValue);}
#line 1718 "parser.c" /* yacc.c:1646  */
    break;


#line 1722 "parser.c" /* yacc.c:1646  */
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
#line 185 "parser.bison" /* yacc.c:1906  */


//prints the line where an error has ocurred
void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}

