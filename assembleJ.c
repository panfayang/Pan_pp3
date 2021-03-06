/**
 * Fayang Pan June 2rd 2014
 *
 * This class deals with J format. The address of the input will be passed to the function by reference,
 * and all the changes will be made on the parameters.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LabelTable.h"

int getRegNbr(char* regName, int line);
void getOpType(char* opcode, char* opType, int* code, int line);
void printBin(int value, int length);
int getNTokens (char * instructionBuffer, int N, char * results[]);

void assembleJ (int opcode, char * restOfStmt, int line, LabelTable table){
    int i;
    char * tokBegin = restOfStmt;
    char * tokEnd;
    char * results[1];
    if (getNTokens(restOfStmt, 1, results) == 1){
        int imm = findLabel(&table, results[0]);
        if (imm == -1){
            printf("This is line %d, the label \"%s\" can't be found in the label table.", line, results[0]);
        }else{
            printBin(opcode, 6);
            printBin(imm>>2, 26);
        }
    }else{
        printf("This is line %d, %s", line, results[0]);
    }
}

