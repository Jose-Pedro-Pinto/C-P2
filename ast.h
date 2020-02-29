
// AST definitions
#ifndef __ast_h__
#define __ast_h__

// AST for expressions
struct _Expr {
  enum { 
    E_INTEGER,
    E_OPERATION,
	E_VARIABLE
  } kind;
  union {
    int value; // for integer values
	char* variable;
    struct { 
      int operator; // PLUS, MINUS, etc 
      struct _Expr* left;
      struct _Expr* right;
    } op; // for binary expressions
  } attr;
};

typedef struct _Expr Expr; // Convenience typedef

// Constructor functions (see implementation in ast.c)
Expr* ast_integer(int v);
Expr* ast_operation(int operator, Expr* left, Expr* right);
Expr* ast_variable(char* Var);

struct _BoolExpr {
    enum {
        E_BOOL = 0x0000,
        RELOP = 0x0011,
        BOL_RIGHT = 0x0110,
        BOL_LEFT = 0x1001,
        DUAL_BOOL = 0x1100
    } type;
    union {
        int value;
        struct {
            int comp_operator;
            Expr *left;
            Expr *right;
            struct _BoolExpr *Bleft;
            struct _BoolExpr *Bright;
        } op;
    } attr;
};

typedef struct _BoolExpr BoolExpr;

//strucure for list of booleans
struct _BoolExprList {
    BoolExpr *current;
	int connect;
    struct _BoolExprList *next;
};

typedef struct _BoolExprList BoolExprList;

BoolExpr *ast_boolexprInt(int value);

BoolExpr *ast_boolexprBool(int operator, BoolExpr *bLeft, BoolExpr *bRight, Expr *left, Expr *right);

BoolExprList *ast_boolExprlist(BoolExpr *expr, int CONNECT ,BoolExprList *next);


//structure for command atribution
struct _Atribution{
	char* VAR;
	int TYPE;
	int INIT_LINE;
	Expr* Value;
	struct _Atribution* nextAtrib;
};

typedef struct _Atribution Atribution;

//structure for a list of arguments of a command
struct _Arg_List{
	struct _Arg_List* next;
	enum {
		EXPR,
		FUNCTION,
		STR,
		LISTBOOL
	}ARG_TYPE;
	union {
		struct _Function* FUNCTION;
		Expr* EXPRESSION;
		char* STR;
		BoolExprList* BOOLEXPR;
	}arg;
};

typedef struct _Arg_List Arg_List;

//strucure for a command(not atribution)
struct _Function {
	char* FUNC_NAME;
	int NUM_ARGS;
	Arg_List* ARGUMENTS;
	struct _COM_LIST* COM_BLOCK;
	struct _Function* COMPLEMENT;
};

typedef struct _Function Function;

//structure for a command
struct _COM {
	enum {
		INIT,
		ATRIB,
		FUNC
	} COMTYPE;
	union {
		Atribution* ATRIB;
		Function* FUNC;
	}COMTENT;
};

typedef struct _COM COM;

//structure for a list of commands
struct _COM_LIST {
	COM* currentCOM;
	struct _COM_LIST* nextCOM;
};

typedef struct _COM_LIST COM_LIST;

//structure for a list of strings
struct _String_Stack{
	char* content;
	struct _String_Stack* next;
};

typedef struct _String_Stack String_Stack;

//structure to hold the entire program
struct _Global_Function{
	int RETURNTYPE;
	char* NAME;
	COM_LIST* COM_BLOCK;
};

typedef struct _Global_Function Global_Function;

//a stack
struct _String_Stack_Holder {
	String_Stack* Stack;
};

typedef struct _String_Stack_Holder String_Stack_Holder;

//headers for all the functions
//defined in ast.c
void add_Stack(String_Stack_Holder* prevStack, char* content);

char* pop_Stack(String_Stack_Holder* Stack);
String_Stack_Holder* create_Holder(String_Stack_Holder* prev);


Atribution* create_Atribution(char* name, int type, int initLine,Atribution* next_Atrib, Expr* AtribExpr);
Global_Function* create_Global_Function(int type, char* name, COM_LIST* block);
COM* create_COM( int com_type, Atribution* newAtrib, Function* newFunc);
COM_LIST* create_COM_LIST (COM* currentCOM, COM_LIST* nextList);
Function* create_Function(char* FUNC_NAME, Arg_List* List, COM_LIST* childBlock, Function* complement);
Arg_List* create_ArgList ( Expr* expression, Function* function, char* STR, BoolExprList* boolexpr, Arg_List* next);
void print_Expression(Expr* express);
void print_BoolExpr(BoolExpr* express);
void print_BoolExprList(BoolExprList* bList);
void print_Atribution(Atribution* atrib, int tabs);
void print_Init(Atribution* atrib, int tabs);
void print_Function(Function* func, int tabs);
void print_COM(COM* com, int tabs);
void print_COM_List(COM_LIST* block, int tabs);
void print_Global_Function(Global_Function* GFunc);
#endif

