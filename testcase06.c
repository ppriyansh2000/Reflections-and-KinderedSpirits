// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase06.c
// =============================
// Test whether the empty tree is considered a reflection of itself and whether
// makeReflection() successfully reflects the empty tree.


#include <stdio.h>
#include "KindredSpirits.h"

int main(void)
{
	// This is a rather round-about way of passing two empty trees to the
	// isReflection() function.
	if (isReflection(makeReflection(NULL), NULL))
		printf("Success!\n");
	else
		printf("fail whale :(\n");

	return 0;
}
