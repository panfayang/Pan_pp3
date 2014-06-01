/**
 * Fayang Pan, April 23, 2014
 * getInstruction class, which takes an opcode, function code in the R format case, 
 * or a register number, all in decimal, and return the respective string representation.
 * The set of instructions can be found at "http://max.cs.kzoo.edu/CS230/Projects/mipsTable.html".
 * The set of registers can be found at "http://max.cs.kzoo.edu/CS230/Projects/mipsRegTable.html".
 */
#include <stdio.h>
#include <string.h>

int translateOpcode(char* opcode){
		if (strcmp(opcode, "addi") == 0) return 8 ;
		if (strcmp(opcode, "addiu") == 0) return 9 ;
		if (strcmp(opcode, "andi") == 0) return 12 ;
		if (strcmp(opcode, "ori") == 0) return 13 ;
		if (strcmp(opcode, "lw") == 0) return 35 ;
		if (strcmp(opcode, "sw") == 0) return 43 ;
		if (strcmp(opcode, "lui") == 0) return 15  ;
		if (strcmp(opcode, "beq") == 0) return 4 ;
		if (strcmp(opcode, "bne") == 0) return 5 ;
		if (strcmp(opcode, "slti") == 0) return 10 ;
		if (strcmp(opcode, "sltiu") == 0) return 11 ;
		if (strcmp(opcode, "j") == 0) return 2 ;
		if (strcmp(opcode, "jal") == 0) return 3 ;
		else return -1;
}

int translateFuncCode(char* funcCode){
		if (strcmp(funcCode, "add") == 0) return 32;
		if (strcmp(funcCode, "addu") == 0) return 33;
		if (strcmp(funcCode, "sub") == 0) return 34 ;
		if (strcmp(funcCode, "subu") == 0) return 35 ;
		if (strcmp(funcCode, "and") == 0) return 36 ;
		if (strcmp(funcCode, "or") == 0) return 37 ;
		if (strcmp(funcCode, "nor") == 0) return 39  ;
		if (strcmp(funcCode, "sll") == 0) return 0 ;
		if (strcmp(funcCode, "srl") == 0) return 2 ;
		if (strcmp(funcCode, "slt") == 0) return 42 ;
		if (strcmp(funcCode, "sltu") == 0) return 43 ;
		if (strcmp(funcCode, "jr") == 0) return 8 ;
		else return -1 ;
}

int translateRegister(char* number){
		if (strcmp(number,"$zero") == 0) return 0 ;
		if (strcmp(number,"$at") == 0) return 1 ;
		if (strcmp(number,"$v0") == 0) return 2 ;
		if (strcmp(number,"$v1") == 0) return 3 ;
		if (strcmp(number,"$a0") == 0) return 4 ;
		if (strcmp(number,"$a1") == 0) return 5 ;
		if (strcmp(number,"$a2") == 0) return 6 ;
		if (strcmp(number,"$a3") == 0) return 7 ;
		if (strcmp(number,"$t0") == 0) return 8 ;
		if (strcmp(number,"$t1") == 0) return 9 ;
		if (strcmp(number,"$t2") == 0) return 10  ;
		if (strcmp(number,"$t3") == 0) return 11 ;
		if (strcmp(number,"$t4") == 0) return 12 ;
		if (strcmp(number,"$t5") == 0) return 13 ;
		if (strcmp(number,"$t6") == 0) return 14 ;
		if (strcmp(number,"$t7") == 0) return 15 ;
		if (strcmp(number,"$s0") == 0) return  16;
		if (strcmp(number,"$s1") == 0) return  17;
		if (strcmp(number,"$s2") == 0) return  18;
		if (strcmp(number,"$s3") == 0) return  19;
		if (strcmp(number,"$s4") == 0) return  20;
		if (strcmp(number,"$s5") == 0) return  21;
		if (strcmp(number,"$s6") == 0) return  22;
		if (strcmp(number,"$s7") == 0) return  23;
		if (strcmp(number,"$t8") == 0) return  24;
		if (strcmp(number,"$t9") == 0) return  25;
		if (strcmp(number,"$k0") == 0) return  26;
		if (strcmp(number,"$k1") == 0) return  27;
		if (strcmp(number,"$gp") == 0) return  28;
		if (strcmp(number,"$sp") == 0) return  29;
		if (strcmp(number,"$fp") == 0) return  30;
		if (strcmp(number,"$ra") == 0) return  31;
		else return -1;
}

