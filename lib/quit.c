/*
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
ARGS:
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
