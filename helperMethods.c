#include<stdio.h>
int translateOpcode(char* opcode);
int translateFuncCode(char* funcCode);
int translateRegister(char* number);

void printBin(int value, int length){

    int max = 1 <<(length -1);
    if (value >= 0){
        while (max>0){
            if (value >= max){
                printf("%d",1);
                value = value - max;
            }else{
                printf("%d",0);
            }
            max = max / 2;
        }
    }else{
        int negative = max*2 + value;
        printBin(negative, length);
    }

}

static char* WRONG_OPCODE = "I can't process the instruction at line number ";
static char* WRONG_REG = "I can't process the register at line number ";
void getOpType(char* opcode, char* opType, int* code, int line){
    int op = translateOpcode(opcode);
    if(op != -1){
        if (op == 2 || op ==3){
            *opType = 'J';
        }else{
            *opType = 'I';
            //printf("OMG!!!!!%s, %d, %d\n", opType, op, line);
        }
        //        printf("This is not the end of the if statement!%d\n", op);
        *code = op;
        //      printf("This is the end of the if statement in helperMethods %d, %d\n", *code, op);
    }else{
        int func = translateFuncCode(opcode);
        if (func != -1){
            *opType = 'R';
            *code = func;
        }else{
            *opType = 'X';
            *code = -1;
            printf("%s%d, and the opcode was %s.\n", WRONG_OPCODE, line, opcode);
        }

    }
    // printf("This is the end of this method: getOpType%s\n",opType);
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
