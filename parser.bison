// Tokens
%token
  VAL
  INT
  FLOAT
  DOUBLE  
  PLUS
  MINUS
  PROD
  DIV
  MOD
  OP_MP
  OP_PP
  OP_BOL
  FALSE
  TRUE
  TYPE
  COM_END
  COM_FUNC
  IF
  ELSE
  WHILE
  EQ
  VAR
  SCANF
  PRINTF
  BR_OP
  BR_CL
  STRING
  PAR_OP
  PAR_CL
  COMMA
  BOOL_AND
  BOOL_OR
  BOOL_OP
  LESS_THAN
  MORE_THAN
  CHECK_EQ
  LESS_EQ_THAN
  MORE_EQ_THAN
  DIFF
  ELSEIF
  RETURN

// Operator associativity & precedence
%left EQ
%left BOOL_AND BOOL_OR
%left OP_BOL
%left PLUS MINUS
%left PROD DIV MOD

// Root-level grammar symbol
%start program;

// Types/values in association to grammar symbols.
%union {
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
}

%type <intValue> VAL
%type <exprValue> expr
%type <com> com
%type <comlist> com_list
%type <VarAtr> initV
%type <VarAtr> call_Atrib
%type <VarAtr> initV_Comp
%type <Funct> call_Func
%type <List> ARGLIST
%type <BList> bool_list
%type <Bool_Expr> bool_expr
%type <Funct> else_part
%type <GlobalFunc> G_Function

// Use "%code requires" to make declarations go
// into both parser.c and parser.h
%code requires {
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
}


//context free grammar
%%
program: G_Function { root = $1;}


G_Function: TYPE VAR PAR_OP PAR_CL BR_OP com_list BR_CL { $$ = create_Global_Function(TYPEval,pop_Stack(StackVar), $6);}

com_list: com com_list { $$ = create_COM_LIST($1,$2); }
		| com { $$ = create_COM_LIST($1, NULL); }
		;

com: initV { $$ = create_COM( INIT, $1, NULL); } 
	| call_Atrib { $$ = create_COM(ATRIB, $1,NULL);}
	| call_Func {$$ = create_COM(FUNC, NULL,$1);}
	;

initV: TYPE VAR EQ expr COM_END { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, NULL, $4); }
	| TYPE VAR COM_END { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,NULL, NULL); }
	| TYPE VAR COMMA initV_Comp COMMA{ $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,$4, NULL); }
	| TYPE VAR EQ expr COMMA initV_Comp { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, $6, $4); }

initV_Comp: VAR COM_END { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,NULL, NULL); }
		  | VAR EQ expr COM_END { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, NULL, $3); }
		  | VAR COMMA initV_Comp { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline,$3, NULL); }
		  | VAR EQ expr COMMA initV_Comp { $$ = create_Atribution(pop_Stack(StackVar), TYPEval, yyline, $5, $3); }

call_Atrib: VAR EQ expr COM_END {$$ = create_Atribution(pop_Stack(StackVar),0, yyline,NULL, $3); }

call_Func: SCANF PAR_OP ARGLIST PAR_CL COM_END {$$ = create_Function("scanf", $3, NULL,NULL);}
		 | PRINTF PAR_OP ARGLIST PAR_CL COM_END {$$ = create_Function("printf", $3, NULL,NULL);}
		 | IF PAR_OP bool_list PAR_CL com { $$ = create_Function("if",create_ArgList(NULL,NULL,NULL, $3,NULL),create_COM_LIST($5,NULL),NULL);}
		 | WHILE PAR_OP bool_list PAR_CL com { $$ = create_Function("while",create_ArgList(NULL,NULL,NULL, $3,NULL),create_COM_LIST($5,NULL),NULL);}
		 | IF PAR_OP bool_list PAR_CL com else_part { $$ = create_Function("if",create_ArgList(NULL,NULL,NULL, $3,NULL),create_COM_LIST($5,NULL),$6);}
		 | IF PAR_OP bool_list PAR_CL BR_OP com_list BR_CL { $$ = create_Function("if",create_ArgList(NULL,NULL,NULL, $3,NULL),$6,NULL);}
		 | IF PAR_OP bool_list PAR_CL BR_OP com_list BR_CL else_part { $$ = create_Function("if",create_ArgList(NULL,NULL,NULL, $3,NULL),$6,$8);}
		 | WHILE PAR_OP bool_list PAR_CL BR_OP com_list BR_CL { $$ = create_Function("while",create_ArgList(NULL,NULL,NULL, $3,NULL),$6,NULL);}
		 | RETURN expr COM_END { $$ = create_Function("return",create_ArgList($2,NULL,NULL, NULL,NULL),NULL,NULL);}

else_part: ELSE com {$$ = create_Function("else",NULL,create_COM_LIST($2,NULL),NULL);}
		 | ELSE BR_OP com_list BR_CL {$$ = create_Function("else",NULL,$3,NULL);}
		 | ELSEIF PAR_OP bool_list PAR_CL com { $$ = create_Function("else if",create_ArgList(NULL,NULL,NULL, $3,NULL),create_COM_LIST($5,NULL),NULL);}
		 | ELSEIF PAR_OP bool_list PAR_CL BR_OP com_list BR_CL { $$ = create_Function("else if",create_ArgList(NULL,NULL,NULL, $3,NULL),$6,NULL);}
		 | ELSEIF PAR_OP bool_list PAR_CL com  else_part { $$ = create_Function("else if",create_ArgList(NULL,NULL,NULL, $3,NULL),create_COM_LIST($5,NULL),$6);}
		 | ELSEIF PAR_OP bool_list PAR_CL BR_OP com_list BR_CL else_part { $$ = create_Function("else if",create_ArgList(NULL,NULL,NULL, $3,NULL),$6,$8);}

ARGLIST:  expr COMMA ARGLIST				{$$ = create_ArgList($1,NULL,NULL,NULL,$3);}
		| expr								{$$ = create_ArgList($1,NULL,NULL,NULL,NULL);}
		| call_Func	COMMA ARGLIST			{$$ = create_ArgList(NULL,$1,NULL,NULL,$3);}
		| call_Func							{$$ = create_ArgList(NULL,$1,NULL,NULL,NULL);}
		| STRING COMMA ARGLIST				{$$ = create_ArgList(NULL,NULL,pop_Stack(StackStr),NULL,$3);}
		| STRING							{$$ = create_ArgList(NULL,NULL,pop_Stack(StackStr),NULL,NULL);}
		| bool_list COMMA ARGLIST			{$$ = create_ArgList(NULL,NULL,NULL,$1,$3);}
		| bool_list							{$$ = create_ArgList(NULL,NULL,NULL,$1,NULL);}
		;

bool_list:	bool_expr						{$$ = ast_boolExprlist($1,0,NULL);}
		|	bool_expr BOOL_AND bool_list    {$$ = ast_boolExprlist($1,BOOL_AND,$3);}
		|   bool_expr BOOL_OR bool_list		{$$ = ast_boolExprlist($1,BOOL_OR,$3);}
		;

bool_expr: TRUE							{ $$ = ast_boolexprInt(1);}
		 | FALSE						{ $$ = ast_boolexprInt(0);}
		 | expr BOOL_OP expr			{ $$ = ast_boolexprBool(BOOL_OP_TYPE, NULL,NULL,$1,$3);}
		 | bool_expr BOOL_OP expr		{ $$ = ast_boolexprBool(BOOL_OP_TYPE,$1,NULL,NULL,$3);}
		 | expr BOOL_OP bool_expr		{ $$ = ast_boolexprBool(BOOL_OP_TYPE,NULL,$3,$1,NULL);}
		 | bool_expr BOOL_OP bool_expr  { $$ = ast_boolexprBool(BOOL_OP_TYPE,$1,$3,NULL,NULL);}
		 |	PAR_OP bool_expr PAR_CL		{$$ = $2;}
		 ;


expr: VAL {$$ = ast_integer($1);}
	| VAR {$$ = ast_variable(pop_Stack(StackVar));}
	| expr PLUS expr { $$ = ast_operation(PLUS,$1,$3);}
	| expr MINUS expr { $$ = ast_operation(MINUS,$1,$3);}
	| expr PROD expr { $$ = ast_operation(PROD,$1,$3);}
	| expr DIV expr { $$ = ast_operation(DIV,$1,$3);}
	| expr MOD expr { $$ = ast_operation(MOD,$1,$3);}
	| PAR_OP expr PAR_CL { $$ = $2;}
	;

%%

//prints the line where an error has ocurred
void yyerror(const char* err) {
  printf("Line %d: %s - '%s'\n", yyline, err, yytext  );
}

