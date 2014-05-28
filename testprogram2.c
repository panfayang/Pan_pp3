/**
 * Author: Fayang Pan
 * Date: 4/14/2014
 * With help from Mehmet and Hayley
 *
 * This is the test class for labelTable.c
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LabelTable.h"

void tableInit(LabelTable* table);
int tableResize (LabelTable * table, int newSize);
int addLabel (LabelTable * table, char * label, int PC);
int findLabel (LabelTable * table, char * label);
void printLabels (LabelTable * table);


int main(){

		LabelEntry staticEntries[5];
		staticEntries[0].label = "Label1";
		staticEntries[0].address = 1000;
		LabelTable testTable;
		testTable.capacity = 5;
		testTable.nbrLabels = 1;
		testTable.entries = staticEntries;
		printf("Label1 should be found: %d\n", findLabel(&testTable, "Label1"));
		printf("Label2 should not be found: %d\n", findLabel(&testTable, "Label2"));
		printLabels(&testTable);
		staticEntries[1].label = "Label2";
		staticEntries[1].address = 1001;
		staticEntries[2].label = "Label3";
		staticEntries[2].address = 1002;
		testTable.entries = staticEntries;
		testTable.nbrLabels = 3;
		printf("Label2 should be found: %d\n", findLabel(&testTable, "Label2"));
		printLabels(&testTable);

		LabelTable test2;
		printf("Initializing a new table\n");
		tableInit(&test2);
		printf("Printing an empty table\n");
		printLabels(&test2);

		addLabel(&test2,"Label0",999);
		printf("Added a new entry, printing a table with one entry\n");
		printLabels(&test2);

		printf("Flushing the table, making it empty, print it.\n");
		tableInit(&test2);
		printLabels(&test2);
		
		printf("Adding two labels\n");
		addLabel(&test2, "Label1", 1000);
		addLabel(&test2, "Label2", 1001);
		printf("Adding a duplicate, should not be reflected in the output.\n");
		addLabel(&test2, "Label2", 1006);
		addLabel(&test2, "Label3", 1002);
		printLabels(&test2);
		printf("Label2 should be found: %d\n", findLabel(&test2, "Label2"));
		printf("Label5 should not be found: %d\n", findLabel(&test2, "Label5"));


}
