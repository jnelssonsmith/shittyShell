/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: halt will kill the process specified by the user in arg. It uses
pkill to search for the process to kill be name. 
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void halt(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);
	int pid_t;
	int errorInt;

	pid_t = fork();
	if (pid_t == 0){
		if (!oneArgReti){
			errorInt = execlp("/usr/bin/pkill", "pkill", arg, NULL);
			if(errorInt){
				printf("Invalid executable specified");
			}
		} else {
			printf("Invalid use of halt\nUsage: halt <program>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}

}
