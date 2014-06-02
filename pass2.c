/*
 * This function reads the lines in an assembly source file and looks
 * for labeled statements.  It builds a table of labels and addresses.
 * It returns a copy of the table it created.  If an error occurs, the
 * function prints an error message and returns the table as it exists
 * at that point (possibly empty).
 *
 * Author: Alyce Brady
 * Date:   2/16/99
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>            /* might be memory.h on some machines */

#include "LabelTable.h"
#include "getToken.h"

void assembleR (int opcode, char * restOfStmt, int line);
void getOpType(char* opcode, char* opType, int* code, int line);

void pass2 (char * filename, LabelTable table)
  /* returns a copy of the label table that was constructed */
{
        FILE * fp;                     /* file pointer */
        char * tokBegin, * tokEnd;     /* used to step thru inst */
        int    PC = 0;                 /* the program counter */
        int    line = 0;
        char   inst[BUFSIZ];           /* will hold instruction; BUFSIZ
                                          is max size of I/O buffer */
        char * opType = (char *)malloc(sizeof(char));
        int *code = (int *)malloc(sizeof(int));
        char * opcodeString;
        char * restOfStatement;
        const char * ERROR1 = "Error: Cannot open file %s.\n";

        /* open the file for reading */
        if ((fp = fopen (filename, "r")) == NULL)
        {
            (void) fprintf (stderr, ERROR1, filename);
        }

        /* Continuously read next line of input until EOF is encountered.
         * Check each line to see if it has a label; if it does, add it
         * to the label table.
         */
        for (PC = 0; fgets (inst, BUFSIZ, fp); PC += 4)
        {
            /* Get rid of comment at end of line (if any).
             * If the line starts with a comment, move on to next line.
             */
            line = PC / 4;
            if ( *inst == '#' ) continue;
            (void) strtok (inst, "#");

            //printf("%s\n",inst);
            /* Skip any leading whitespace. */
            tokBegin = inst;
            getToken (&tokBegin, &tokEnd);
                /* tokBegin now points to 1st non-whitespace character
                 * in the token and tokEnd points to 1st punctuation mark
                 * or whitespace after the end of the token.
                 */

           // printf("I am here! %s\n",tokBegin);
            if ( *(tokEnd) == ':' ) {
                tokBegin = tokEnd + 1;
                getToken(&tokBegin, &tokEnd);
                if ( *tokBegin == '\0' || *tokEnd == '\0'){
                    continue;
                }
            }
            opcodeString = tokBegin;
            //printf("Here is the opcodeString: %s\n", tokBegin);
            *tokEnd = '\0';
            restOfStatement = tokEnd+1;
            //printf("At least it's alright here! %s\n", restOfStatement);
            
            getOpType(opcodeString, opType, code, line);

           // printf("Att least it's alright here! And here is the opType: %d\n",*code );
           // printf("IAMWRONG, %s\n", opType);
            if (strcmp(opType,"R")==0){
                //printf("This is before assembleR: %s, with code %d \n", restOfStatement, *code);
                assembleR(*code, restOfStatement, line);
            }
            printf("\n");
        }
        /* EOF */
        (void) fclose (fp);
}
