/**
 * Fayang Pan April 23 2014
 * processIFormat class, which takes in a I format MIPS machine language and translate it into assembly language
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char string[], int begin, int end);
char * translateOpcode(int opcode);
char * translateRegister(int number);
const int WORD_LEN = 4;

char * processIFormat(char * buffer){
		int opcode = binToDec(buffer, 0, 5);
		int rs = binToDec(buffer, 6, 10);
		int rt = binToDec(buffer, 11, 15);
		int imm = binToDec(buffer, 16, 31);
		char result[50];
		strcpy(result, translateOpcode(opcode));
		strcat(result, "\t");
		if (opcode > 7 && opcode < 14){
				strcat(result, translateRegister(rt));
				strcat(result, ", ");
				strcat(result, translateRegister(rs));
				strcat(result, ", ");
				char temp[33];
				sprintf(temp, "%d", imm);
				strcat(result,temp);
		}
		else if (opcode == 4 || opcode ==5){
				strcat(result, translateRegister(rs));
				strcat(result, ", ");
				strcat(result, translateRegister(rt));
				strcat(result, ", ");
				imm	= imm * 4;
				char temp[33];
				sprintf(temp, "%d", imm);
				strcat(result, temp);
		}
		else if (rt == 0){
				strcat(result, translateRegister(rs));
				strcat(result, ", ");
				char temp[33];
				sprintf(temp, "%d", imm);
				strcat(result, temp);
		}
		else if (opcode == 43 || opcode == 35){
				strcat(result, translateRegister(rt));
				strcat(result, ", ");
				char temp[33];
				sprintf(temp, "%d(", imm);
				strcat(result,temp);
				strcat(result, translateRegister(rs));
				strcat(result, ")");
		}


		strcat(result, "\n");
		return result;
}
