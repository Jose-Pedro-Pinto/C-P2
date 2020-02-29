#include "parser.h"
#include "ast.h"
#include "stack.h"
#include <string.h>

//constructor for a instruction
//intruction load constant
//loads a constant(a value)
Instr* LDC (int toAdd){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_LDC;
	NewPiece -> NUM = toAdd;
	return NewPiece;
}

//constructor for a instruction
//intruction addition
//adds two values and returns the result
Instr* ADI (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_ADI;
	return NewPiece;
}

//constructor for a instruction
//intruction subtraction
//subtracts two values and returns the result
Instr* SBI (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_SBI;
	return NewPiece;
}

//constructor for a instruction
//intruction multiplication
//multiplies two values and returns the result
Instr* MPI (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_MPI;
	return NewPiece;
}

//constructor for a instruction
//intruction division
//divides two values and returns the result
Instr* DIVI (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_DIV;
	return NewPiece;
}

//constructor for a instruction
//intruction > (greater than)
//checks if the first value is greater than the second
Instr* GRT (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_GRT;
	return NewPiece;
}

//constructor for a instruction
//intruction == (equal to)
//checks if the first value is equal to the second
Instr* EQU (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_EQU;
	return NewPiece;
}

//constructor for a instruction
//intruction != (not equal to | different of)
//checks if the first value is different of the second
Instr* NEQ (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_NEQ;
	return NewPiece;
}

//constructor for a instruction
//intruction >= (greater than or equal to)
//checks if the first value is greater than or equal to the second
Instr* GEQ (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_GEQ;
	return NewPiece;
}

//constructor for a instruction
//intruction <= (lesser than or equal to)
//checks if the first value is lesser than or equal to the second
Instr* LEQ (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_LEQ;
	return NewPiece;
}

//constructor for a instruction
//intruction < (lesser than)
//checks if the first value is lesser than the second
Instr* LES (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_LES;
	return NewPiece;
}

//constructor for a instruction
//intruction load variable
//loads a variable
Instr* LOD (char* var){
	Instr* NewPiece = malloc(sizeof(Instr));
	char* Varcpy = malloc(sizeof(char) * (strlen(var) + 1));
	strcpy(Varcpy,var);
	NewPiece -> kind = I_LOD;
	NewPiece -> Variable = Varcpy;
	return NewPiece;
}

//constructor for a instruction
//intruction store variable
//stores a variable
Instr* STO (char* var){
	Instr* NewPiece = malloc(sizeof(Instr));
	char* Varcpy = malloc(sizeof(char) * (strlen(var) + 1));
	strcpy(Varcpy,var);
	NewPiece -> Variable = Varcpy;
	NewPiece -> kind = I_STO;
	return NewPiece;
}

//constructor for a instruction
//intruction label
//creates a label(to jump to)
Instr* LABEL(int jump_Index, char* label){
    Instr* NewPiece = malloc(sizeof(Instr));
    char* Labelcpy;
    int power;
    if(label == NULL)
    {
        for(power = 1; jump_Index> (10 ^ power); power++);
        Labelcpy = malloc(sizeof(char) * (power + 2));
        sprintf(Labelcpy,"L%d",jump_Index);
    }
    else
    {
        Labelcpy = malloc(sizeof(char) * (strlen(label) + 1));
        strcpy(Labelcpy,label);
    }
    NewPiece -> kind = I_LABEL;
    NewPiece -> Variable = Labelcpy;
    return NewPiece;
}

//constructor for a instruction
//intruction OR
//verifies if one of two booleans is true
Instr* IOR (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_IOR;
	return NewPiece;
}

//constructor for a instruction
//intruction AND
//verifies if both of two booleans is true
Instr* ANDI (){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_ANDI;
	return NewPiece;
}

//constructor for a instruction
//intruction False jump
//recieves a boolean, if it is false jumps to a label
Instr* FJP(int jump_Index){
    Instr* NewPiece = malloc(sizeof(Instr));
    char* Labelcpy;
    int power;

    for(power = 1; jump_Index>(10 ^ power); power++);
    Labelcpy = malloc(sizeof(char) * (power + 2));
    sprintf(Labelcpy,"L%d",jump_Index);
    NewPiece -> kind = I_FJP;
    NewPiece -> Variable = Labelcpy;
    return NewPiece;
}

//constructor for a instruction
//intruction Jump
//jumps to a label
Instr* UJP (int jump_Index, char* label){
    Instr* NewPiece = malloc(sizeof(Instr));
    char* Labelcpy;
    int power;
    if(label == NULL)
    {
        for(power = 1; jump_Index> (10 ^ power); power++);
        Labelcpy = malloc(sizeof(char) * (power + 2));
        sprintf(Labelcpy,"L%d",jump_Index);
    }
    else
    {
        Labelcpy = malloc(sizeof(char) * (strlen(label) + 1));
        strcpy(Labelcpy,label);
    }
    NewPiece -> kind = I_UJP;
    NewPiece -> Variable = Labelcpy;
    return NewPiece;
}


//constructor for a instruction
//intruction Return
//exits the current function(in this case, only main; ends program)
Instr* RET (Arg_List* arglist){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_RET;
	NewPiece -> Arguments = arglist;
	return NewPiece;
}

//constructor for a instruction
//intruction print
//prints a list of arguments to the standard output
Instr* PRINT (Arg_List* arglist){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> str_start = malloc(sizeof(int) * 3);
	NewPiece -> str_length = malloc(sizeof(int) * 3);
	NewPiece -> kind = I_PRINT;
	NewPiece -> Arguments = arglist;
	parse_string(arglist -> arg.STR, NewPiece -> str_start, NewPiece -> str_length);
	return NewPiece;
}

//constructor for a instruction
//intruction scan
//reads a value from the standard output
//places it on a variable
Instr* SCAN (Arg_List* arglist){
	Instr* NewPiece = malloc(sizeof(Instr));
	NewPiece -> kind = I_SCAN;
	NewPiece -> Arguments = arglist;
	return NewPiece;
}

//obtains the first instruction from a list of instructions
Instr* getInstr( InstrList* List){
	return List -> code;
}

//obtains the tail of a list of instructions(all instructions except for the first)
InstrList* tail( InstrList* List){
	return List -> next;
}

//returns the concatenation of tow list of intructions
InstrList* append (InstrList* List1, InstrList* List2){
	InstrList* temp = List1;

	if(List1 == NULL) return List2;
	if(List2 == NULL) return List1;

	while(tail(temp) != NULL) temp = tail(temp);

	temp -> next = List2;
	return List1;
}

//creates a new list of intructions
InstrList* mkList(Instr* code, InstrList* List){
	InstrList* NewList = malloc(sizeof(InstrList));
	NewList -> code = code;
	NewList -> next = List;
	return NewList;
}

//prints the mips code of an instruction to the standard output
void printInstr (Instr* Instruction){
	switch (Instruction -> kind)
	{
		case I_LDC:		add_VarStack(Instruction);
						break;
		case I_ADI:		op_VarStack(I_ADI);
						break;
		case I_SBI:		op_VarStack(I_SBI);
						break;
		case I_MPI:		op_VarStack(I_MPI);
						break;
		case I_DIV:		op_VarStack(I_DIV);
						break;
		case I_GRT:		op_VarStack(I_GRT);
						break;
		case I_LES:		op_VarStack(I_LES);
						break;
		case I_EQU:		op_VarStack(I_EQU);
						break;
		case I_NEQ:		op_VarStack(I_LES);
						break;
		case I_GEQ:		op_VarStack(I_GEQ);
						break;
		case I_LEQ:		op_VarStack(I_LEQ);
						break;
		case I_LOD:		add_VarStack(Instruction);
						break;
		case I_STO:		printf("addi $sp, $sp, 4\n"); 
						printf("lw $t1, ($sp)\n");
						printf("sw $t1, %s\n",Instruction -> Variable); 
						break;

		case I_LABEL:	printf("%s:\n", Instruction -> Variable);
						break;
		case I_FJP:		fjp(Instruction);
						break;
		case I_IOR:		printf("IOR\n");
						break;
		case I_ANDI:	printf("ANDI\n");
						break;
		case I_UJP:		printf("j %s\n",Instruction -> Variable);
						break;
		case I_RET:		returnOP(Instruction->Arguments);
						break;
		case I_SCAN:	scanit(Instruction);
						break;
		case I_PRINT:	printit(Instruction);
						break;
		default:		printf("Error\n");
	}
}

//prints the mips code of a list of instructions to the standard output
void printInstrList (InstrList* List){
	InstrList* temp = List;
	while(temp != NULL)
	{
		printInstr(getInstr(temp));
		temp = tail(temp);
	}

}

//turns an expression into a list of instrucions in p-code
InstrList* compileExpr(Expr* expression){
	InstrList* List;
	switch (expression -> kind)
	{
		case E_INTEGER:		List = mkList(LDC(expression -> attr.value),NULL);
							break;

		case E_OPERATION:	List = append (compileExpr( expression -> attr.op.left), compileExpr(expression -> attr.op.right));
							switch (expression -> attr.op.operator)
							{
								case PLUS:	List = append(List, mkList(ADI(),NULL));	break;

								case MINUS:	List = append(List, mkList(SBI(), NULL));	break;

								case PROD:	List = append(List, mkList(MPI(), NULL));	break;

								case DIV:	List = append(List, mkList(DIVI(), NULL));	break;
							}
							break;
		case E_VARIABLE:	List = mkList(LOD(expression -> attr.variable),NULL);
							break;
	}

	return List;
}

//turns a bolean expression into a list of instrucions in p-code
InstrList* compileBoolExpr(BoolExpr* bexpr){
	InstrList* List;
	switch ( bexpr -> type)
	{
		case E_BOOL:	List = mkList(LDC(bexpr -> attr.value),NULL);
						break;

		default:		if(bexpr -> type & 0x0010) List = compileExpr(bexpr -> attr.op.left);
						else List = compileBoolExpr(bexpr -> attr.op.Bleft);

						if(bexpr -> type & 0x0001) List = append(List,compileExpr(bexpr -> attr.op.right));
						else List = append(List,compileBoolExpr(bexpr -> attr.op.Bright));

						switch(bexpr -> attr.op.comp_operator)
						{
							case MORE_THAN:		List = append(List, mkList(GRT(),NULL)); break;
							case LESS_THAN:		List = append(List, mkList(LES(),NULL)); break;
							case CHECK_EQ:		List = append(List, mkList(EQU(),NULL)); break;
							case DIFF:			List = append(List, mkList(NEQ(),NULL)); break;
							case MORE_EQ_THAN:	List = append(List, mkList(GEQ(),NULL)); break;
							case LESS_EQ_THAN:	List = append(List, mkList(LEQ(),NULL)); break;
						}
						break;
	}

	return List;
}

//turns the entire program into a list of instructions in p-code
InstrList* compile(Global_Function* Global){
    int *jump_Index = malloc(sizeof(int) * 4);
    *jump_Index = 0;
    InstrList* List = compileGFunction(Global);
    return append(List, compileBlock(Global -> COM_BLOCK,jump_Index));
}

//turns a list of commands into a list of instrucions in p-code
InstrList* compileBlock(COM_LIST* block, int* jump_Index){
	InstrList* List = NULL;
	COM_LIST* temp = block;
	while(temp != NULL)
	{
		List = append(List, compileCOM(temp -> currentCOM, jump_Index));
		temp = temp -> nextCOM;
	}
	return List;
}

//turns a command into a list of instrucions in p-code
InstrList* compileCOM(COM* com,int* jump_Index){
	if(com -> COMTYPE == FUNC) return compileFunction(com -> COMTENT.FUNC,jump_Index,0);
	else if (com -> COMTYPE == ATRIB) return compileAtribution(com -> COMTENT.ATRIB);
	return compileInit(com -> COMTENT.ATRIB);

}

//turns a list of bolean expressions into a list of instrucions in p-code
InstrList* compileConditions(BoolExprList* bool_list){
	InstrList* List = NULL;
	BoolExprList* temp = bool_list;
	int connect = 0;


	while(temp != NULL)
	{
		List = append(List,compileBoolExpr(temp -> current));
		if(connect == BOOL_OR)	List = append(List,mkList(IOR(),NULL));
		else if(connect == BOOL_AND)	List = append(List,mkList(ANDI(),NULL));
		connect = temp -> connect;
		temp = temp -> next;
	}
	
	return List;
}

//turns a command(not atributions) into a list of instrucions in p-code
InstrList* compileFunction(Function* function, int* jump_Index, int end_Block){
	InstrList* List = NULL;
	int Blockable_Function = 0, label;
	if(strcmp(function -> FUNC_NAME, "if") == 0)
	{
		Blockable_Function = 1;
		end_Block = *jump_Index;
		label = *jump_Index + 1;
		*jump_Index = *jump_Index + 2;
		List = compileConditions(function -> ARGUMENTS -> arg.BOOLEXPR);

	}
	else if(strcmp(function -> FUNC_NAME, "else if") == 0)
	{
		Blockable_Function = 1;
		label = *jump_Index;
		*jump_Index = *jump_Index + 1;
		List = compileConditions(function -> ARGUMENTS -> arg.BOOLEXPR);
	}
	else if(strcmp(function -> FUNC_NAME, "else") == 0)
	{
		List = compileBlock(function -> COM_BLOCK,jump_Index);
		List = append(List, mkList(LABEL(end_Block,NULL),NULL));
	}
	else if(strcmp(function -> FUNC_NAME, "while") == 0)
	{
		label = *jump_Index;
		end_Block = *jump_Index + 1;
		*jump_Index = *jump_Index + 2;
		List = mkList(LABEL(label,NULL),NULL);
		List = append(List,compileConditions(function -> ARGUMENTS -> arg.BOOLEXPR));
		List = append(List,mkList(FJP(end_Block),NULL));
		List = append(List, compileBlock(function -> COM_BLOCK,jump_Index));
		List = append(List, mkList(UJP(label,NULL),NULL));
		List = append(List, mkList(LABEL(end_Block,NULL),NULL));
	}
	else if(strcmp(function -> FUNC_NAME, "return") == 0)
	{
		List = mkList(RET(function -> ARGUMENTS),NULL);
	}
	else if(strcmp(function -> FUNC_NAME, "printf") == 0)
	{
		List = mkList(PRINT(function -> ARGUMENTS),NULL);
	}
	else if(strcmp(function -> FUNC_NAME, "scanf") == 0)
	{
		List = mkList(SCAN(function -> ARGUMENTS),NULL);
	}

	if(Blockable_Function)
	{
		if(function -> COMPLEMENT == NULL) List = append(List,mkList(FJP(end_Block),NULL));
		else	List = append(List,mkList(FJP(label),NULL));
		List = append(List, compileBlock(function -> COM_BLOCK,jump_Index));
		if(function -> COMPLEMENT != NULL)
		{
			List = append(List, mkList(UJP(end_Block,NULL),NULL));
			List = append(List, mkList(LABEL(label,NULL),NULL));
			List = append(List,compileFunction(function -> COMPLEMENT, jump_Index, end_Block));	
		}
		else	List = append(List, mkList(LABEL(end_Block,NULL),NULL));
	}
	return List;
}

//turns an atribution into a list of instrucions in p-code
InstrList* compileAtribution(Atribution* Atrib){
	InstrList* List = mkList(LOD(Atrib -> VAR),NULL);
	List = append(List,compileExpr(Atrib -> Value));
	List = append(List, mkList(STO(Atrib -> VAR),NULL));
	return List;
}

//creates the nssecary variables to start turning the program into p-code
InstrList* compileInit(Atribution* init){
	if(init -> Value == NULL)
	{
		if(init -> nextAtrib != NULL)	return compileInit(init -> nextAtrib);
		else return NULL;
	}

	InstrList* List = mkList(LOD(init -> VAR),NULL);
	List = append(List,compileExpr(init -> Value));
	List = append(List, mkList(STO(init->VAR),NULL));
	if(init -> nextAtrib != NULL) List = append(List, compileInit(init -> nextAtrib));
	return List;
}

//turns a command(not atributions) into a list of instrucions in p-code
InstrList* compileGFunction (Global_Function* Function){
	return mkList(LABEL(0,Function -> NAME),NULL);
}

//turns load instrucions into mips(load consant and load variable)
void add_VarStack(Instr* toLoad){
	switch(toLoad -> kind){
		case I_LDC:		printf("li $t1, %d\n", toLoad->NUM);
						break;
		case I_LOD:		printf("lw $t1, %s\n", toLoad->Variable);
						break;
	}
	printf("sw $t1, ($sp)\n");
	printf("addi $sp,$sp,-4\n");
}

//turns boolean expreccions into mips
void op_VarStack(int OPType){
	int order = 1;
	printf("addi $sp, $sp, 4\n"); 
	printf("lw $t1, ($sp)\n");
	printf("addi $sp, $sp, 4\n");
	printf("lw $t2, ($sp)\n");
	switch(OPType){
		case I_ADI:		printf("add ");
						break;
		case I_SBI:		printf("sub ");
						break;
		case I_MPI:		printf("mul ");
						break;
		case I_DIV:		printf("div ");
						break;
		case I_GEQ:		printf("sle ");
						order = 0;
						break;
		case I_LES:		printf("slt ");
						break;
		case I_NEQ:		printf("sne ");
						break;
		case I_LEQ:		printf("sle ");
						break;
		case I_GRT:		printf("slt ");
						order = 0;
						break;
		case I_EQU:		printf("seq ");
						break;
		case I_ANDI:	printf("and ");
						break;
		case I_IOR:		printf("or ");
						break;
	}

	if (!order)	printf("$t1,$t1,$t2\n");
	else printf("$t1,$t2,$t1\n");
	printf("sw $t1, ($sp)\n");
	printf("addi $sp, $sp, -4\n");
}

/*VarList* rem_var(VarList* varlist,char* var){
	if (!strcmp(varlist->variable,var)){
		if (varlist->next==NULL){
			varlist->variable=NULL;
			return varlist;
		}
		return varlist->next;
	}
	VarList* prev=varlist;
	VarList* this=varlist;
	while (this->next!=NULL){
		if(!strcmp(this->variable,var)){
			prev->next=this->next;
			return varlist;
		}
		prev = this;
		this=this->next;
	}
	if (!strcmp(this->variable,var)){
		prev->next=NULL;
	}
	return varlist;
}*/

//adds a variable
VarList* add_var(VarList* list,char* var){
	VarList* temp = (VarList*) malloc(sizeof(VarList)),*oldtemp = list;
	temp->next=NULL;
	temp->variable=malloc(sizeof(char) * (strlen(var) + 1));
	strcpy(temp->variable,var);
	if (list==NULL){
		return temp;
	}
	while (oldtemp->next!=NULL){
		oldtemp=oldtemp->next;
	}
	oldtemp->next=temp;
	return list;
}

extern VarList* str_List;
extern VarList* variable_List;

//turns a list of variables into mips
void print_varList(){
	int i = 0;
	printf(".data\n");
	VarList* temp=variable_List;
	while (temp!=NULL){
		printf("%s: 0\n",temp->variable);
		temp=temp->next;
	}
	temp = str_List;
	while(temp!=NULL){
		printf("str%d: .asciiz %s\n",i,temp->variable);
		temp=temp->next;
		i++;
	}
	printf(".text\n");
}

//parses a string into tokens
//tokens of tow forms
//%d
//anything else
void parse_string(char* string, int* start, int* length){
    VarList* string_list = str_List;
    int i=0, exit = 0,j;
    char* token= malloc(sizeof(char) * (strlen(string)+1));
    *length = 0;
    if(str_List == NULL) *start = 0;
    else
    {
        *start = 1;
        while(string_list -> next != NULL)
        {
            *start = *start + 1;
            string_list = string_list -> next;
        }
    }

    while(i < strlen(string)){
        exit = 0;
        j = 0;
        for(;i < strlen(string) && exit != 1;i++)
        {
            if(j == 0 && string[i] != '"')
            {
                token[j] = '"';
                j++;
            }


            if(string[i] == '%' && string[i + 1] == 'd')
            {
                token[j] = '"';
                token[j + 1] = '\0';
                i = i + 1;
                exit = 1;
            }
            else
            {
                token[j] = string[i];
            }
            j++;
        }
        if(j == 1) token[j]='"';
        str_List=add_var(str_List,token);
        memset(token,0,strlen(string)+1);
        *length = *length + 1;
    }
    free(token);
}	

//turns a false jump instruction into mips
void fjp(Instr* label){
    printf("addi $sp, $sp, 4\n"); 
    printf("lw $t1, ($sp)\n");
    printf("beq $t1, 0, %s\n",label->Variable);
}

//turns a print instruction into mips
void printit(Instr* Instruction){
	int start = *(Instruction -> str_start), length = *(Instruction -> str_length) + start;
	Arg_List* current_Arg= Instruction -> Arguments -> next;
	for(; start<length ;start++)
	{
		printstring(start);
		if(current_Arg != NULL)
		{
			printvar(current_Arg -> arg.EXPRESSION -> attr.variable);
			current_Arg = current_Arg -> next;
		}
	}
}

//returns mips code to print a string
void printstring(int string_counter){
    printf("li $v0, 4\n");
    printf("la $a0, str%d\n",string_counter);
    printf("syscall\n");
}

//returns mips code to print a variable
void printvar(char* var){
    printf("li $v0, 1\n");
    printf("lw $a0, %s\n",var);
    printf("syscall\n");
}

//turns a scan instruction into mips
void scanit(Instr* Instruction){
	char* variable = Instruction -> Arguments -> next -> arg.EXPRESSION -> attr.variable;
	int i;
	printf("li $v0, 5\n");
	printf("syscall\n");
	printf("addi $t1, $v0, 0\n");
	printf("sw $t1, ");
	for(i=1;i<strlen(variable);i++)
	{
		printf("%c",variable[i]);
	}
	printf("\n");
}

//does something, maybe
void returnOP(Arg_List* list){
	printf("j returnZone\n\n\n");
	printf("returnZone:\n");
	printInstrList(compileExpr(list -> arg.EXPRESSION));
}
