/**
 * Fayang Pan April 23 2014
 * processJFormat class, which takes in a J format MIPS machine language and translate it into assembly language
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char string[], int begin, int end);
char * translateOpcode(int opcode);
char * translateRegister(int number);
const int WORD_LEN;

char * processJFormat(char * buffer){
		int opcode = binToDec(buffer, 0, 5); 
		int add = binToDec(buffer, 6, 31);
		char result[50];
		strcpy(result, translateOpcode(opcode));
		strcat(result, "\t");
		if (opcode > 7 && opcode < 14){
				char temp[33];

				sprintf(temp, "%d", add*WORD_LEN);
				strcat(result,temp);
		}   

		return result;
}
