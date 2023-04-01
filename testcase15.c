// Sean Szumlanski
// COP 3502, Fall 2020

// =============================
// Kindred Spirits: testcase15.c
// =============================
// NOTE! This test case *must* compile, run, and print "Success!" when placed in
// a directory with only the following three files:
//
//   1. KindredSpirits.c
//   2. KindredSpirits.h
//   3. testcase15.c
//
// If it doesn't compile, that might be an indication that you're relying on the
// create_node() function from my other test case source files. You cannot
// assume that there will always be a create_node() function defined for you
// when your KindredSpirits.c source file is compile with a test case file. If
// you want to call a create_node() function in your KindredSpirits.c file, you
// must write a create_node() function in that file (albeit with a different
// function name, so it won't conflict with the create_node() function in my
// test cases when you try to compile).


#include <stdio.h>
#include "KindredSpirits.h"

int main(void)
{
	printf("%s\n", kindredSpirits(NULL, NULL) ? "Success!" : "fail whale :(");
	return 0;
}
