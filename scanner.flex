%{
// HEADERS
#include <stdlib.h>
#include "parser.h"

// variables maintained by the lexical analyser
int yyline = 1;
String_Stack_Holder* StackStr = NULL;
String_Stack_Holder* StackVar = NULL;

int OPval;
int TYPEval;
int FUNCval;
int BOOL_OP_TYPE;
%}

%option noyywrap
%%
[ \t\r]+ {  }
#.*\n { yyline++; }
\n { yyline++; }
"//"[^\n\r]* { }

\-?[0-9]+ { 
   yylval.intValue = atoi(yytext);
   return VAL; 
}
"+"  { return PLUS;}
"\-"  { return MINUS;}
"\*" { return PROD;}
"\/" { return DIV;}
[%]  { return MOD;}
"=" { return EQ; }
"TRUE" { return TRUE;}
"FALSE" { return FALSE; }
"int" { TYPEval = INT; return TYPE; }
"float" { TYPEval = FLOAT; return TYPE; }
"double" { TYPEval = DOUBLE; return TYPE; }
"," {return COMMA;}
";" {return COM_END; }
"scanf" {return SCANF;}
"printf" { return PRINTF;}
"if" { return IF;}
"while" {return WHILE;}
"else" {return ELSE; }
"else if" {return ELSEIF;}
"{" {return BR_OP; }
"}" {return BR_CL; }
"(" {return PAR_OP;}
")" {return PAR_CL;}
"&&" {return BOOL_AND;}
"||" {return BOOL_OR;}
"<" {BOOL_OP_TYPE = LESS_THAN; return BOOL_OP; }
">" {BOOL_OP_TYPE = MORE_THAN; return BOOL_OP; }
"==" {BOOL_OP_TYPE = CHECK_EQ; return BOOL_OP; }
"<=" {BOOL_OP_TYPE = LESS_EQ_THAN; return BOOL_OP; }
">=" {BOOL_OP_TYPE = MORE_EQ_THAN; return BOOL_OP; }
"!=" {BOOL_OP_TYPE = DIFF; return BOOL_OP; }
"return" {return RETURN;}
"\""[^\"]*"\"" {if(!StackStr) StackStr = create_Holder(StackStr); add_Stack(StackStr, yytext); return STRING;}
&?[0-9a-zA-Z_]+ {if(!StackVar) StackVar = create_Holder(StackVar); add_Stack(StackVar,yytext); return VAR; }

.  { printf("%d",yytext[0]); yyerror("unexpected character"); }
%%

