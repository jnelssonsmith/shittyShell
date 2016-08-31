/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void clear(char arg[256]){
	int clearReti;

	clearReti = validateNoArgs(arg);
	if(!clearReti){
		system("clear");
	} else {
		printf("Invalid use of clear\nUsage: clear [no arguments]\n");
	}
}
