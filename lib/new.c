/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Uses c file I/O to create new file in cwd with name given by arg
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "validation.c"

void new(char arg[256]){

	int oneArgReti = validateOneArg(arg);
	int pid_t;

	pid_t = fork();

	if (pid_t == 0){
		if (!oneArgReti){
			execlp("/usr/bin/touch", "touch", arg, NULL);
		} else {
			printf("Invalid use of new\nUsage: new <file>\n");
		}
		exit(0);
	} else if (pid_t < 0){
		printf("Error with process creation for new");
	} else {
		wait(NULL);
	}


}
