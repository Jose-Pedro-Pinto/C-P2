#include <stdio.h>
#include "parser.h"
#include "ast.h"
#include "stack.h"

//evaluates expressions
//not in use
int eval(Expr* expr) {
  int result = 0;
  if (expr == 0) {
    yyerror("Null expression!!");
  }
  else if (expr->kind == E_INTEGER) {
    result = expr->attr.value; 
  } 
  else if (expr->kind == E_OPERATION) {
    int vLeft = eval(expr->attr.op.left);
    int vRight = eval(expr->attr.op.right);
    switch (expr->attr.op.operator) {
      case PLUS: 
        result = vLeft + vRight; 
        break;
	  case MINUS:
		result = vLeft - vRight;
		break;
	  case PROD:
		result = vLeft * vRight;
		break;
	  case DIV:
		result = vLeft / vRight;
		break;
	  case MOD:
		result = vLeft % vRight;
		break;
      default: yyerror("Unknown operator!");
    }
  }
  return result;
}

VarList* str_List = NULL;
VarList* variable_List = NULL;

int main(int argc, char** argv) {
  extern Global_Function* root;
  InstrList* rootList;
  --argc; ++argv;
  if (argc != 0) {
    yyin = fopen(argv[0], "r");
    if (!yyin) {
      printf("'%s': could not open file\n", *argv);
      return 1;
    }
  } //  yyin = stdin	
  FILE *fp;
  if (yyparse() == 0) {
      rootList = compile(root);
      fp = freopen(argv[1], "w+", stdout); 
      print_varList();
      printInstrList(rootList);
  }
  fclose(fp);
  return 0;


}
