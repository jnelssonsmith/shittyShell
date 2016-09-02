/*
START DATE: 25/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Run uses execlp to execute the file specified by arg, the user can
specify a complete path to the executable, or execute something in the cwd with
./executable-name
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void run(char arg[256]){
	char fullPath[1280];
	int oneArgReti = validateOneArg(arg);
	int pid_t;
	char prePath[1024];
	int returnval;

	pid_t = fork();
	if (pid_t == 0){
		if (!oneArgReti){
			returnval = execlp(arg, NULL);
			if(returnval){
				printf("That program could not be found\n");
			}
		} else {
			printf("Invalid use of run\nUsage: run <program>\n");
		}
		exit(0);
	} else if (pid_t < 0){
		printf("Error creating process");
	} else {
		wait(NULL);
	}
}
