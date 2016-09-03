/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Uses touch to create new file given by arg
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "validation.c"

void new(char arg[256]){

	int oneArgReti = validateOneArg(arg);
	pid_t pid;

	pid = fork();

	if (pid == 0){
		if (!oneArgReti){
			execlp("/usr/bin/touch", "touch", arg, NULL);
		} else {
			printf("Invalid use of new\nUsage: new <file>\n");
		}
		exit(0);
	} else if (pid < 0){
		printf("Error with process creation for new");
	} else {
		wait(NULL);
	}


}
