#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int getRegNbr(char* regName, int line);
void getOpType(char* opcode, char* opType, int* code, int line);
void printBin(int value, int length);
int getNTokens (char * instructionBuffer, int N, char * results[]);

void assembleR (int opcode, char * restOfStmt, int line){
    int i;
    char * tokBegin = restOfStmt;
    char * tokEnd;

    if(opcode == 8){
        char * results[1];
        if (getNTokens(restOfStmt, 1, results) == 1){
            int s = getRegNbr(results[0],line);
            if(s != -1){
                printBin(0, 6);
                printBin(s, 5);
                printBin(0, 15);
                printBin(8, 6);
            }else{
                //printf("This is line %d, the register number is invalid.", line);
            }
        }else{
            printf("This is line %d, %s", line, results[0]);
        }
    }else{
        char * results[3];
        if (getNTokens(restOfStmt, 3, results) == 1){
            int d = getRegNbr(results[0],line);
            if(d != -1){
                int s = getRegNbr(results[1],line);
                if (s != -1){
                    int t;
                    if (opcode == 0 || opcode == 2){
                        t = atoi(results[2]);
                        if (t == 0 && strcmp(results[2],"0") != 0){
                            //printf("This is line %d, the shift amount is in the wrong format", line);
                        }else{
                            printBin(0, 6);
                            printBin(0, 5);
                            printBin(s, 5);
                            printBin(d, 5);
                            printBin(t, 5);
                            printBin(opcode, 6);
                        }
                    }else{
                        t = getRegNbr(results[2], line);
                        if (t == -1){
                            //printf("This is line %d, there is something wrong with T register.", line);
                        }else{
                            printBin(0, 6);
                            printBin(s, 5);
                            printBin(t, 5);
                            printBin(d, 5);
                            printBin(0, 5);
                            printBin(opcode, 6);
                        }
                    }
                }else{
                    //printf("This is line %d, there is something wrong with S register.", line);
                }
            }else{
                //printf("This is line %d, there is something wrong with D register.", line);
            }
        }else{
            printf("%s", results[0]);
        }
    }
}
