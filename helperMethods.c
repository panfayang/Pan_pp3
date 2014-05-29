#include<stdio.h>

void printBin(int value, int length){

	int max = 1 <<(length -1);
	while (max>0){
		if (value >= max){
			printf("%d",1);
			value = value - max;
		}else{
			printf("%d",0);
		}
		max = max / 2;
	}

}

static char* WRONG_OPCODE = "I can't process the instruction at line number ";
static char* WRONG_REG = "I can't process the register at line number ";
void getOpType(char* opcode, char* opType, int* code, int line){
	int func = translateFuncCode(opcode);
	if(func != -1){
		opType = "R";
		code = func;
	}else{
		func = translateOpcode(opcode);
		if (func != -1){
			if (func == 2 || func ==3){
				opType = "J";
			}else{
				opType = "I";
			}
			code = func;
		}else{
			opType = "X";
			code = -1;
			printf("%s%d, and the opcode was %s.\n", WRONG_OPCODE, line, opcode);
		}
	
	}

}

int getRegNbr(char* regName, int line){
	int reg =  translateRegister(regName);
	if (reg!=-1){
		return reg;
	}else{
		printf("%s%d, and the register name was %s.\n", WRONG_REG, line, regName);
		return -1;
	}

}
