// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase05.c
// =============================
// Test whether the empty tree is considered a reflection of itself.


#include <stdio.h>
#include "KindredSpirits.h"

int main(void)
{
	// Compare two empty trees. They should be considered reflections by
	// definition; see pg. 4 of the assignment PDF.
	if (isReflection(NULL, NULL))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	return 0;
}
