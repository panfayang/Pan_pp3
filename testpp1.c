/*
 * Test Driver to test verifyMIPSInstruction and binToDec.
 *
 * This program reads lines from a file.  For each line, the program
 *      calls verifyMIPSInstruction.  If the line contains a valid
 *      MIPS instruction, the program calls binToDec for various
 *      segments of the instruction to test the binToDec function.
 *
 * Input:
 *      The program reads its input from a file passed in as a parameter
 *      on the command line, or reads from the standard input.
 *      To test verifyMIPSInstruction, the file should contain ...
 *
 *              DESCRIBE NECESSARY TEST CASES HERE
 *
 * Output:
 *      For each valid line, the program prints a series of decimal
 *      numbers to test binToDec, representing
 *
 *              DESCRIBE NECESSARY TEST CASES HERE
 *
 *      For each invalid line, the program prints an error message to
 *      stderr saying so.  (The program also prints an error message if
 *      it cannot open the file.)
 *
 * Author:Fayang Pan 
 *        with assistance from: Dr. Alyce Brady
 *
 * Creation Date:  Apr 12, 2014
 *        modified: Modification_Date        reason
 *        modified: Modification_Date        reason
 *
 */

/* include files go here */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char string[], int begin, int end);
int verifyMIPSInstruction (char string[]);

int main(int argc, char *argv[])
{
		char buffer[BUFSIZ];
		FILE* fptr;                           /* file pointer */
		int   lineNum = 0;

		/* Was a file passed in a parameter (e.g., on the command line)? */
		if ( argc == 2 )
		{
				/* Open the file for reading */
				if ((fptr = fopen (argv[1], "r")) == NULL)
				{
						fprintf (stderr, "Error: Cannot open file %s.\n", argv[1]);
						return 1;
				}
		}
		else  /* No file passed in; use standard input. */
				fptr = stdin;

		/* Continuously read next line of input until EOF is encountered.
		 * Each line should contain only 32 characters and newline.
		 */
		while (fgets (buffer, BUFSIZ, fptr))   /* fgets returns NULL if EOF */
		{
				lineNum++;

				if (strlen (buffer) == 33 && buffer[32] == '\n')
						buffer[32] = '\0';        /* convert newline to null byte */
				else
				{
						(void) fprintf (stderr,
										"Error: line %d does not have 32 chars.\n", lineNum);
						continue;                /* error: get next line */
				}

				/* Verify that the string is 32 0's and 1's.  If it is, do
				 * various tests to ensure that binToDec works correctly.
				 * If the string contains invalid characters, print an error
				 * message.
				 */
				if (verifyMIPSInstruction(buffer)==1){
						printf("Yes! Line %d is a valid MIPS instruction!\n\tHere are some binary to Decimal conversions from index:\n"
										"\t0 to 5: %d,\n"
										"\t6 to 10: %d,\n"
										"\t11 to 15: %d,\n" 
										"\t16 to 20: %d,\n"
										"\t21 to 25: %d,\n"
										"\t26 To 31: %d.\n", lineNum, binToDec(buffer, 0,5), binToDec(buffer, 6,10), binToDec(buffer, 11,15), binToDec(buffer, 16,20), binToDec(buffer, 21,25), binToDec(buffer,26,31));
						
				}else{
						printf("Nope... Line %d is not a valid MIPS instruction..\n", lineNum);
				}

		}

		/* End-of-file encountered; close the file. */
		fclose (fptr);
		return 0;
}
