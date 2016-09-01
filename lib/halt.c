/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void halt(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);

	if(!oneArgReti){
		strcpy(cmdarg, "pkill ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of halt\nUsage: halt <program>\n");
	}
/*
	int pid;

	pid = fork();
	if (pid == 0){
		if (!oneArgReti){
			execlp("/bin/pkill", "9", arg, NULL);
		} else {
			printf("Invalid use of halt\nUsage: halt <program>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
	*/



}
