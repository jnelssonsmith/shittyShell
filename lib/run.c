/*
START DATE: 25/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Run uses execlp to execute the file specified by arg, it also makes
use of the getcwd argument to get the entire path rather than a relative path.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void run(char arg[256]){
	char fullPath[1280];
	int oneArgReti = validateOneArg(arg);
	int pid;
	char prePath[1024];

	pid = fork();
	if (pid == 0){
		if (!oneArgReti){
			getcwd(prePath, sizeof(prePath));
			strcpy(fullPath, prePath);
			strcat(fullPath, "/");
			strcat(fullPath, arg);
			execlp(fullPath, NULL);
		} else {
			printf("Invalid use of run\nUsage: run <program>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}


}
