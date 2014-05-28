/**
 * Fayang Pan, April 23, 2014
 * getInstruction class, which takes an opcode, function code in the R format case, 
 * or a register number, all in decimal, and return the respective string representation.
 * The set of instructions can be found at "http://max.cs.kzoo.edu/CS230/Projects/mipsTable.html".
 * The set of registers can be found at "http://max.cs.kzoo.edu/CS230/Projects/mipsRegTable.html".
 */

char * translateOpcode(int opcode){
		if (opcode == 8) return  "addi";
		if (opcode == 9) return  "addiu";
		if (opcode == 12) return  "andi";
		if (opcode == 13) return  "ori";
		if (opcode == 35) return  "lw";
		if (opcode == 43) return  "sw";
		if (opcode == 15) return  "lui";
		if (opcode == 4) return  "beq";
		if (opcode == 5) return  "bne";
		if (opcode == 10) return  "slti";
		if (opcode == 11) return  "sltiu";
		if (opcode == 2) return  "j";
		if (opcode == 3) return  "jal";
		else return "NA";
}

char * translateFuncCode(int funcCode){
		if (funcCode == 32) return  "add";
		if (funcCode == 33) return  "addu";
		if (funcCode == 34) return  "sub";
		if (funcCode == 35) return  "subu";
		if (funcCode == 36) return  "and";
		if (funcCode == 37) return  "or";
		if (funcCode == 39) return  "nor";
		if (funcCode == 0) return  "sll";
		if (funcCode == 2) return  "srl";
		if (funcCode == 42) return  "slt";
		if (funcCode == 43) return  "sltu";
		if (funcCode == 8) return  "jr";
		else return "NA";
}

char * translateRegister(int number){
		if (number == 0) return "$zero";
		if (number == 1) return "$at";
		if (number == 2) return "$v0";
		if (number == 3) return "$v1";
		if (number == 4) return "$a0";
		if (number == 5) return "$a1";
		if (number == 6) return "$a2";
		if (number == 7) return "$a3";
		if (number == 8) return "$t0";
		if (number == 9) return "$t1";
		if (number == 10) return "$t2";
		if (number == 11) return "$t3";
		if (number == 12) return "$t4";
		if (number == 13) return "$t5";
		if (number == 14) return "$t6";
		if (number == 15) return "$t7";
		if (number == 16) return "$s0";
		if (number == 17) return "$s1";
		if (number == 18) return "$s2";
		if (number == 19) return "$s3";
		if (number == 20) return "$s4";
		if (number == 21) return "$s5";
		if (number == 22) return "$s6";
		if (number == 23) return "$s7";
		if (number == 24) return "$t8";
		if (number == 25) return "$t9";
		if (number == 26) return "$k0";
		if (number == 27) return "$k1";
		if (number == 28) return "$gp";
		if (number == 29) return "$sp";
		if (number == 30) return "$fp";
		if (number == 31) return "$ra";
		else return "NA";
}

