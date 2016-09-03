/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: clears the screen
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"


void clear(char arg[256]){
	pid_t pid;
	int clearReti = validateNoArgs(arg);

	pid = fork();
	if(pid == 0){
		if(!clearReti){
			execlp("/usr/bin/clear", "clear", NULL);
		} else {
			printf("Invalid use of clear\nUsage: clear [no arguments]\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}

}
