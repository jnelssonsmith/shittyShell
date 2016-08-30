/*
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
ARGS:
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void pauseCLI(char arg[256], char input[256]){
	int nullArgReti = validateNoArgs(arg);
	if(!nullArgReti){
		printf("Press enter to continue...");
		fgets(input, 256, stdin);
	} else {
		printf("Invalid use of pause\nUsage: pause [no arguments]\n");
	}

}
