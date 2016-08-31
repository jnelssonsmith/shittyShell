/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void quit(char arg[256]){
	int nullArgReti = validateNoArgs(arg);
	if(!nullArgReti){
		exit(0);
	} else {
		printf("Invalid use of quit\nUsage: quit [no arguments]\n");
	}
}
