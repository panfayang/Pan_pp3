/* 
 * This is a driver to test pass1 and the Label Table functions.
 *
 * Author: Alyce Brady
 * Date: 2/18/99
 */

#include <stdio.h>
#include "LabelTable.h"

LabelTable pass1 (char * filename);
void printBin(int value, int length);
void pass2 (char * filename, LabelTable table);

int main (int arc, char* argv[])
{
        LabelTable table;
        int i;
        table = pass1 (argv[1]);
//        printLabels (&table);
	printf("\n");
        pass2(argv[1], table);

        return 0;
}
