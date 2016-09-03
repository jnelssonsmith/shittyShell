/*
START DATE: 29/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: This function was not required in the assignment spec but using
the shell without an explicit command to see the pwd was very frustrating.
Because of this, "whereami" was implemented to show the path to where the user
currently is. Whereami ensures that the arg string passed is empty, then calls
the unix command "pwd" to print out the path to the working directory.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void whereami(char arg[256]){
	char cmdarg[300];
	int nullArgReti = validateNoArgs(arg);
	pid_t pid;

	pid = fork();
	if(pid == 0){
		if (!nullArgReti) {
			execlp("/bin/pwd", "pwd", NULL);
		} else {
			printf("Invalid use of whereami\nUsage: whereami [NO ARGS]\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
}
