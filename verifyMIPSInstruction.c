/*
 * verifyMIPSInstruction
 *
 * This function verifies that the string provided to it as a paramater
 * contains 32 characters representing binary digits (characters '0' and
 * '1'), followed by a null byte.
 *
 *   int verifyMIPSInstruction (char * instruction);
 *
 *	    Pre-condition:  instruction is a null-terminated string
 *	    Post-condition: the characters in "instruction" have not
 *			    been modified
 *	    Returns: 1 if instr contained 32 characters representing binary
 *			   digits ('0' and '1') followed by a null byte
 *
 * Implementation:
 *	Describe interesting implementation details here, if any.
 *      (HOW does this function work?  What non-trivial data structures
 *	or algorithms does it use?  Does it have performance
 *	characteristics that the user should be aware of?)
 *
 * Author: Fayang Pan 
 *	with assistance from: N.A.
 *
 * Creation Date: Apr 12, 2014 
 *	modified: Modification_Date	reason
 *	modified: Modification_Date	reason
 *
 */

#include <string.h>

int verifyMIPSInstruction (char * instr)
  /*  returns 1 if instr contains 32 characters representing binary
   *  digits ('0' and '1'); 0 otherwise
   */
{
		int length = 0;
		int counter = 0;
		while(*instr != '\0'){
				length++;
				if (*instr != '1' && *instr != '0'){
						return 0;
				}
				instr++;
		}

		if (length == 32){
			return 1;
		}
		return 0;
}
