#ifndef __stack_h__
#define __stack_h__

//used to know what the instruction in p-code is
//one for every type of instruction
typedef enum {
	I_LDC,
	I_ADI,
	I_SBI,
	I_MPI,
	I_DIV,
	I_LOD,
	I_STO,
	I_RDI,
	I_FJP,
	I_GRT,
	I_UJP,
	I_LABEL,
	I_EQU,
	I_NEQ,
	I_GEQ,
	I_LEQ,
	I_LES,
	I_IOR,
	I_ANDI,
	I_RET,
	I_SCAN,
	I_PRINT,
} IKind;

//the instruction structure
//has the kind of instruction
//has several atributes
//some of the atributes might be 'NULl'
struct _Instr {
	IKind kind;
	int NUM;
	char* Variable;
	int* str_start;
	int* str_length;
	Arg_List* Arguments;
};

typedef struct _Instr Instr;

//a structure to hold several instructions(a list of instrucions)
struct _InstrList {
	Instr* code;
	struct _InstrList* next;
};

typedef struct _InstrList InstrList;

//a structure to hold several variables(a list of variables)
struct _VarList{
	char* variable;
	struct _VarList* next;
};

typedef struct _VarList VarList;

//headers for all the funcions
//all these are defined in stack.c
Instr* LDC (int toAdd);
Instr* ADI ();
Instr* SBI ();
Instr* MPI ();
Instr* DIVI ();
Instr* GRT ();
Instr* EQU ();
Instr* NEQ ();
Instr* GEQ ();
Instr* LEQ ();
Instr* LES ();
Instr* LOD (char* var);
Instr* STO (char* var);
Instr* LABEL(int jump_Index, char* label);
Instr* IOR ();
Instr* FJP(int jump_Index);
Instr* UJP (int jump_Index, char* label);
Instr* RET (Arg_List* arglist);
Instr* PRINT (Arg_List* arglist);
Instr* SCAN (Arg_List* arglist);
Instr* getInstr( InstrList* List);
InstrList* tail( InstrList* List);
InstrList* append (InstrList* List1, InstrList* List2);
InstrList* mkList(Instr* code, InstrList* List);
void printInstr (Instr* Instruction);
void printInstrList (InstrList* List);
InstrList* compileExpr(Expr* expression);
InstrList* compileBoolExpr(BoolExpr* bexpr);
InstrList* compileCOM(COM* com, int* jump_Index);
InstrList* compileAtribution(Atribution* Atrib);
InstrList* compileInit(Atribution* init);
InstrList* compileGFunction (Global_Function* Function);
InstrList* compile(Global_Function* Global);
InstrList* compileConditions(BoolExprList* bool_list);
InstrList* compileFunction(Function* function, int* jump_Index, int end_Block);
InstrList* compileBlock(COM_LIST* block, int* jump_Index);
InstrList* compile(Global_Function* Global);
void add_VarStack(Instr* toLoad);
void op_VarStack(int OPType);
void fjp(Instr* label);
VarList* rem_var(VarList* varlist,char* var);
VarList* add_var(VarList* list,char* var);
void print_varList();
void parse_string(char* string, int* start, int* length);
void printvar(char* var);
void printstring(int string_counter);
void printit(Instr* Instruction);
void scanit(Instr* Instruction);
void returnOP(Arg_List* list);
#endif
