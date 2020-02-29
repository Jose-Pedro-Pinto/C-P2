// AST constructor functions

#include <stdlib.h> // for malloc
#include "ast.h" // AST header
#include "string.h"
#include "parser.h"
#include "stack.h"

//constructor for an expression
//just an integer
Expr* ast_integer(int v) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_INTEGER;
  node->attr.value = v;
  return node;
}


//constructor for an expression
//opperations bettwen two expressions
//+;-;*,/,etc
Expr* ast_operation
(int operator, Expr* left, Expr* right) {
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_OPERATION;
  node->attr.op.operator = operator;
  node->attr.op.left = left;
  node->attr.op.right = right;
  return node;
}

//constructor for an expression
//just a variable
Expr* ast_variable(char* Var){
  Expr* node = (Expr*) malloc(sizeof(Expr));
  node->kind = E_VARIABLE;
  node->attr.variable = malloc(sizeof(char) * strlen(Var) + 1);
  strcpy(node->attr.variable, Var);
  return node;
}

//constructor for a boolean expression
//just true,false
BoolExpr *ast_boolexprInt(int value) {
    BoolExpr *node = (BoolExpr *) malloc(sizeof(BoolExpr));
    node->type = E_BOOL;
    node->attr.value = value;
    return node;
}

//constructor for a boolean expression
//opperations bettwen two boolean expressions
// >,<,==,etc
BoolExpr *ast_boolexprBool(int operator, BoolExpr *bLeft, BoolExpr *bRight, Expr *left, Expr *right) {
    BoolExpr *node = (BoolExpr *) malloc(sizeof(BoolExpr));
    node->attr.op.comp_operator = operator;

    if (right != NULL) {
        node->attr.op.right = right;
        if (left != NULL) {
            node->type = RELOP;
            node->attr.op.left = left;
        } else if (bLeft != NULL) {
            node->type = BOL_LEFT;
            node->attr.op.Bleft = bLeft;
        }
    } else if (bRight != NULL) {
        node->attr.op.Bright = bRight;
		
        if (left != NULL) {
            node->type = BOL_RIGHT;
            node->attr.op.left = left;
        } else if (bLeft != NULL) {
            node->type = DUAL_BOOL;
            node->attr.op.Bleft = bLeft;
        }
    }
    return node;
}

//creates a list of boolean expressions
BoolExprList* ast_boolExprlist(BoolExpr *expr,int CONNECT, BoolExprList *next) {
    BoolExprList *node = (BoolExprList *) malloc(sizeof(BoolExprList));
    node->current = expr;
	node->connect = CONNECT;
    node->next = next;
	return node;
}
extern VarList* variable_List;

//creates the command atribution
Atribution* create_Atribution(char* name, int type, int initLine,Atribution* next_Atrib, Expr* AtribExpr){
	Atribution* newAtr = malloc(sizeof(Atribution));
	newAtr -> VAR = malloc(sizeof(char) * strlen(name) + 1);
	strcpy(newAtr -> VAR, name);
	newAtr -> TYPE = type;
	if(type != 0) variable_List = add_var(variable_List,name);
	newAtr -> INIT_LINE = initLine;
	newAtr -> Value = AtribExpr;
	newAtr -> nextAtrib = next_Atrib;
	return newAtr;
}

//creates a command
COM* create_COM( int com_type, Atribution* newAtrib, Function* newFunc){
	COM* newCom = malloc(sizeof(COM));
	newCom -> COMTYPE = com_type;
	if(com_type == FUNC) newCom -> COMTENT.FUNC = newFunc;
	else newCom -> COMTENT.ATRIB = newAtrib;
	return newCom;
}

//creates a list of commands
COM_LIST* create_COM_LIST (COM* currentCOM, COM_LIST* nextList){
	COM_LIST* newList = malloc(sizeof(COM_LIST));
	newList -> currentCOM = currentCOM;
	newList -> nextCOM = nextList;
	return newList;
}

//creates the list of arguments of a command
Arg_List* create_ArgList ( Expr* express, Function* function, char* str,BoolExprList* boolexpr ,Arg_List* next){
	Arg_List* List = malloc(sizeof(Arg_List));
	List-> next = next;
	if(express!=NULL) { List -> ARG_TYPE = EXPR; List -> arg.EXPRESSION = express; }
	else if(function!=NULL) { List -> ARG_TYPE = FUNCTION; List -> arg.FUNCTION = function; }
	else if(str!=NULL) { List -> ARG_TYPE = STR; List->arg.STR = malloc(sizeof(char) * strlen(str) + 1); strcpy( List->arg.STR, str); }
	else { List -> ARG_TYPE = LISTBOOL; List -> arg.BOOLEXPR = boolexpr; }
	return List;
}



//creates a command(not an atribution)
Function* create_Function(char* FUNC_NAME, Arg_List* List, COM_LIST* childBlock, Function* complement){
	int Arg_Num=0;
	Function* newFunc = malloc(sizeof(Function));
	newFunc -> FUNC_NAME = malloc(sizeof(char) * (strlen(FUNC_NAME) + 1));
	strcpy(newFunc -> FUNC_NAME, FUNC_NAME);
	newFunc -> ARGUMENTS = List;
	Arg_List* tmp = List;
	while( tmp != NULL )
	{
		Arg_Num++;
		tmp = tmp -> next;
	}
	newFunc -> NUM_ARGS = Arg_Num;
	newFunc -> COM_BLOCK = childBlock;
	newFunc -> COMPLEMENT = complement;
	return newFunc;
}

//creates the structures for the entire program(commands,boolean expressions,expressions)
Global_Function* create_Global_Function(int type, char* name, COM_LIST* block){
    Global_Function* newGlFunction = malloc(sizeof(Global_Function));
    newGlFunction -> RETURNTYPE = type;
    newGlFunction -> COM_BLOCK = block;
    newGlFunction -> NAME = malloc(sizeof(char) * (strlen(name)+1));
    strcpy(newGlFunction -> NAME, name);
    return newGlFunction;
}

//prints an expression to the standard output
void print_Expression(Expr* express){
	printf("( ");
	if(express -> kind == E_INTEGER) printf("%d", express->attr.value);
	else if(express -> kind == E_VARIABLE) printf("%s", express->attr.variable);
	else
	{
		print_Expression(express -> attr.op.left);
		switch (express -> attr.op.operator)
		{
			case PLUS: printf("+ "); break;
			case MINUS: printf("- "); break;
			case PROD: printf("* "); break;
			case DIV: printf("/ "); break;
			case MOD: printf("%% "); break;
		}
		print_Expression(express -> attr.op.right);
	}
	printf(" ) " );
}

//prints a boolean expression to the standard output
void print_BoolExpr(BoolExpr* express){
	printf("( ");
	if(express -> type == E_BOOL)
	{
		if(express->attr.value == 0) printf("FALSE");
		else printf("TRUE");
	}
	else
	{
        if (express->type & 0x0010) print_Expression(express -> attr.op.left);
		else print_BoolExpr(express -> attr.op.Bleft);
		switch (express -> attr.op.comp_operator)
		{
			case MORE_THAN: printf("> "); break;
			case LESS_THAN: printf("< "); break;
			case CHECK_EQ: printf("== "); break;
			case DIFF: printf("!= "); break;
			case MORE_EQ_THAN: printf("<= "); break;
			case LESS_EQ_THAN: printf(">= "); break;
		}
		if (express->type & 0x0001) print_Expression(express -> attr.op.right);
		else print_BoolExpr(express -> attr.op.Bright);
	}
	printf(" ) " );
}

//prints a list of boolean expressions to the standard output
void print_BoolExprList(BoolExprList* bList){
	BoolExprList* temp = bList;
	while(temp!=NULL)
	{
		print_BoolExpr(temp -> current);
		if(temp -> connect == BOOL_AND) printf(" && ");
		else if(temp -> connect == BOOL_OR) printf(" || ");
		temp = temp -> next;
	}
}

//prints an antribution to the standard output
void print_Atribution(Atribution* atrib, int tabs){
	int tab_index;
	for(tab_index = 0; tab_index < tabs; tab_index++) printf("\t");
	printf("%s = ", atrib -> VAR);
	print_Expression(atrib -> Value);
	printf(" ;\n");
}

//inicializes the printing of the program to the standard output
void print_Init(Atribution* atrib, int tabs){
	int tab_index;
	Atribution* temp = atrib;
	for(tab_index = 0; tab_index < tabs; tab_index++) printf("\t");
	if(atrib -> TYPE == INT) printf("int ");
	else if (atrib -> TYPE == FLOAT) printf("float ");
	else if (atrib -> TYPE == DOUBLE) printf("double ");
	while(temp != NULL) { 
		printf("%s", temp -> VAR);
		if(temp -> Value != NULL)
		{
			printf("= ");
			print_Expression(temp -> Value);
		}
		if(temp -> nextAtrib != NULL) printf(", ");
		temp = temp -> nextAtrib;
	}
	printf(" ;\n");
	
}

//prints a command(not an atribution) to the standard output
void print_Function(Function* func, int tabs){
	int arg_index = 1, tab_index;
	Arg_List* temp = func -> ARGUMENTS;
	for(tab_index = 0; tab_index < tabs; tab_index++) printf("\t");
	if(strcmp ( func -> FUNC_NAME, "return") == 0)
	{
		printf("return ");
		print_Expression(temp -> arg.EXPRESSION);
		printf(";\n");
	}
	else
	{
		printf("%s ", func -> FUNC_NAME);
		if(func -> NUM_ARGS > 0)
		{
			printf("( ");
			for(; arg_index <= func -> NUM_ARGS; temp = temp -> next, arg_index++) 
			{
				if(temp -> ARG_TYPE == EXPR) print_Expression(temp -> arg.EXPRESSION);
				else if(temp -> ARG_TYPE == STR) printf(" ( %s ) ",temp->arg.STR); 
				else if(temp -> ARG_TYPE == FUNCTION) print_Function(temp->arg.FUNCTION,0); 
				else print_BoolExprList(temp->arg.BOOLEXPR);

				if(arg_index != func -> NUM_ARGS) printf(", ");
			}
			printf(") ");
		}
		
		if(func -> COM_BLOCK != NULL)
		{
			printf("\n");
			for(tab_index = 0; tab_index < tabs; tab_index++) printf("\t");
			printf("{\n");
			print_COM_List(func -> COM_BLOCK, tabs + 1);
			for(tab_index = 0; tab_index < tabs; tab_index++) printf("\t");
			printf("}\n");
		}
	
		else printf(" ;\n");

		if(func -> COMPLEMENT != NULL) print_Function(func -> COMPLEMENT, tabs);
	}

}

//prints a command to the standard output
void print_COM(COM* com, int tabs){
	if(com -> COMTYPE == FUNC) print_Function(com -> COMTENT.FUNC, tabs);
	else if (com -> COMTYPE == ATRIB) print_Atribution(com -> COMTENT.ATRIB, tabs);
	else print_Init(com -> COMTENT.ATRIB, tabs);
	
}

//prints a list of commands to the standard output
void print_COM_List(COM_LIST* block, int tabs){
	if(block!=NULL)
	{
		print_COM(block -> currentCOM, tabs);
		print_COM_List(block -> nextCOM, tabs);
	}
}

//prints the entire program to the standard output
void print_Global_Function(Global_Function* GFunc){
	if(GFunc -> RETURNTYPE == INT) printf("int ");
	else if (GFunc -> RETURNTYPE == FLOAT) printf("float ");
	else if (GFunc -> RETURNTYPE == DOUBLE) printf("double ");
	else printf("error finding function type");

	printf("%s () {\n", GFunc -> NAME);
	print_COM_List(GFunc -> COM_BLOCK, 1);
	printf("}");
}

//ads to the stack
void add_Stack(String_Stack_Holder* prevStack, char* content){
	String_Stack* newStack = malloc(sizeof(String_Stack)), *tmp;
	newStack -> content = realloc(newStack ->content, sizeof(char) * (strlen(yytext) + 1));
	strcpy(newStack -> content,content);
	if(prevStack -> Stack != NULL)
	{
		tmp = prevStack -> Stack;
		while(tmp -> next != NULL) tmp = tmp -> next;
		tmp -> next = newStack;
	}
	else prevStack -> Stack = newStack;
}

//removes and returns from the stack
char* pop_Stack(String_Stack_Holder* Stack){
    char* returnValue;
    String_Stack* tmp = Stack -> Stack,*tmp1 = NULL;
    if(tmp != NULL)
    {
        while (tmp -> next != NULL)
        {
            tmp1 = tmp;
            tmp = tmp -> next;
        }
    }
    returnValue = malloc(sizeof(char) * (strlen(tmp -> content) + 1));
    strcpy(returnValue, tmp -> content);
    free(tmp -> content);
    free(tmp);
    tmp = NULL;
    if(tmp1 != NULL) tmp1 -> next = NULL;
    else Stack -> Stack = NULL;
    return returnValue;
}

//creates the stack?
String_Stack_Holder* create_Holder(String_Stack_Holder* prev){
    String_Stack_Holder* Holder;
    if(prev == NULL)
    {
        Holder = malloc(sizeof(String_Stack_Holder));
        Holder -> Stack = NULL;
        return Holder;
    }
    return prev;
}
