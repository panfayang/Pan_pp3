/**
 * Fayang Pan April 23 2014
 * processRFormat class, which takes in a R format MIPS machine language and translate it into assembly language
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char string[], int begin, int end);
char * translateOpcode(int opcode);
char * translateFuncCode(int funcCode);
char * translateRegister(int number);


char * processRFormat(char * buffer){
		int opcode = binToDec(buffer, 0, 5);
		int rs = binToDec(buffer, 6, 10);
		int rt = binToDec(buffer, 11, 15);
		int rd = binToDec(buffer, 15, 20);
		int shift = binToDec(buffer, 21, 25);
		int funct = binToDec(buffer, 26, 31);
		char result[50];
		if (opcode == 0){
				strcpy(result, translateFuncCode(funct));
		}else{
				strcpy(result, translateOpcode(opcode));
		}

		strcat(result, "\t");

		if (shift != 0 && rs == 0){
				strcat(result, translateRegister(rd));
				strcat(result, ", ");
				strcat(result, translateRegister(rt));
				strcat(result, ", ");
				char temp[33];
				sprintf(temp,"%d", shift);
				strcat(result,temp);
		}
		else if(shift == 0){
				if (rt == 0 && rd == 0){
						strcat(result, translateRegister(rs));
				}else{
						strcat(result, translateRegister(rd));
						strcat(result, ", ");
						strcat(result, translateRegister(rs));
						strcat(result, ", ");
						strcat(result, translateRegister(rt));
				}
		}

		strcat(result, "\n");
		return result;
}

