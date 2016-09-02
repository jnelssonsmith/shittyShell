/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
input - the dummy input to read in when 'pausing'.
DESCRIPTION: Pause works by simply waiting for user input, because the program
will be unable to complete any other commands while waiting for I/O from user.
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
