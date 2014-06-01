#include <stdio.h>

void assembleR (int opcode, char * restOfStmt, int line){
    int i;
    char * tokBegin = instructionBuffer;
    char * tokEnd;

    if(opcode == 8){
        char * results[1];
        if (getNTokens(restOfStmt, 1, results) == 1){
            int s = translateRegister(results[0]);
            if(s != -1){
                printBin(0, 6);
                printBin(s, 5);
                printBin(0, 15);
                printBin(8, 6);
            }else{
                printf("This is line %d, the register number is invalid.", line);
            }
        }else{
            printf("This is line %d, %s", line, result[0]);
        }
    }else{
        char * results[3];
        if (getNTokens(restOfStmt, 3, results) == 1){
            int d = translateRegister(result[0]);
            if(d != -1){
                int s = translateRegister(result[1]);
                if (s != -1){
                    int t;
                    if (opcode == 0 || opcode == 2){
                        t = atoi(result[2]);
                        if (t == 0 && strcmp(result[2],"0") != 0){
                            printf("This is line %d, the shift amount is in the wrong format", line);
                        }else{
                            printBin(0, 6);
                            printBin(0, 5);
                            printBin(s, 5);
                            printBin(d, 5);
                            printBin(t, 5);
                            printBin(opcode, 6);
                        }
                    }else{
                        t = translateRegister(result[2]);
                        if (t == -1){
                            printf("This is line %d, there is something wrong with T register", line);
                        }
                    }


                }else{
                    printf("This is line %d, the t register is invalid");
                }
            }else{
                int d == translateRegister(result[])
            }
        }
    }
}


}


