/* 
 * This is a driver to test pass1 and the Label Table functions.
 *
 * Author: Alyce Brady
 * Date: 2/18/99
 */

#include <stdio.h>
#include "LabelTable.h"

LabelTable pass1 (char * filename);

int main ()
{
        LabelTable table;
        int i;

        table = pass1 ("testfile");

        printLabels (&table);
	printBin(30,9);
	printf("\n");
        return 0;
}
