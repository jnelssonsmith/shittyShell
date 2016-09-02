/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Echo is fed the argument that has matched the quote regex and had
the quotes striped via strsep
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void echo(char arg[256]){
	int echoReti = validateQuoteArg(arg);
	int pid;
	char arg1[256];
	char arg2[256];

	pid = fork();
	if (pid == 0){
		if (!echoReti){
			strsep(&arg, "\"");
			strcpy(arg2, strsep(&arg, "\""));
			execlp("/bin/echo", "echo", arg2, NULL);
		} else {
			printf("Invalid use of echo\nUsage: echo \"<comment>\"\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
}
