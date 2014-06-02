/**
 * Fayang Pan June 2rd 2014
 *
 * This class deals with I format. The address of the input will be passed to the function by reference,
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

void assembleI (int opcode, char * restOfStmt, int line, LabelTable table){
    int i;
    char * tokBegin = restOfStmt;
    char * tokEnd;

    // In case of lui
    if(opcode == 15){
        char * results[2];
        if (getNTokens(restOfStmt, 2, results) == 1){
            int t = getRegNbr(results[0],line);
            if(t != -1){
                int imm = atoi(results[1]);
                if (imm == 0 && strcmp(results[1],"0") != 0){
                    //printf("This is line %d, the immediate is wrong.", line);
                }else{
                    printBin(opcode, 6);
                    printBin(0, 5);
                    printBin(t, 5);
                    printBin(imm, 16);
                }
            }else{
                //printf("This is line %d, there is something wrong with the t register.", line);
            }
        }else{
            printf("This is line %d, %s", line, results[0]);
        }
    }

    else {
        char * results[3];
        if (getNTokens(restOfStmt, 3, results) == 1){
            // in case of lw and sw
            if(opcode == 35 || opcode ==43){
                int t = getRegNbr(results[0],line);
                if(t != -1){
                    int imm = atoi(results[1]);
                    if (imm == 0 && strcmp(results[1],"0") != 0){
                        //printf("This is line %d, the immediate is wrong.", line);
                    }else{
                        int s = getRegNbr(results[2], line);
                        if (s != -1){
                            printBin(opcode, 6);
                            printBin(s, 5);
                            printBin(t, 5);
                            printBin(imm, 16);
                        }else{
                            //printf("This is line %d, there is something wrong with the s register.", line);
                        }
                    }
                }else{
                    //printf("This is line %d, there is something wrong with the t resiger.", line);
                }
            }

            // in case of beq and bne
            else if (opcode == 4 || opcode == 5){
                int s = getRegNbr(results[0],line);
                if(s != -1){ 
                    int t = getRegNbr(results[1], line);
                    if (t != -1){
                        int offset = findLabel(&table, results[2]);
                        if (offset == -1){
                            printf("This is line %d, and the label \"%s\" is not found in the label table", line, results[2]);
                        }else{
                            offset = (offset>>2) - line -1;
                            printBin(opcode, 6);
                            printBin(s, 5);
                            printBin(t, 5);
                            printBin(offset, 16);
                        }
                    }else{
                        //printf("This is line %d, there is something wrong with the t register.", line);
                    }
                }else{
                    //printf("This is line %d, there is something wrong with the s resiger.", line);
                }

            }

            else{
                int t = getRegNbr(results[0],line);
                if(t != -1){
                    int s = getRegNbr(results[1], line);
                    if (s != -1){
                        int imm = atoi(results[2]);
                        if (imm == 0 && strcmp(results[2],"0") != 0){
                            //printf("This is line %d, the immediate is wrong.", line);
                        }else{
                            printBin(opcode, 6);
                            printBin(s, 5);
                            printBin(t, 5);
                            printBin(imm, 16);
                        }
                    }else{
                       // printf("This is line %d, there is something wrong with the s register.", line);
                    }
                }else{
                    //printf("This is line %d, there is something wrong with the t resiger.", line);
                }
            }
        }else{
             printf("This is line %d, %s", line, results[0]);
        }
    }
}
