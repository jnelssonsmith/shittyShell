#include <stdio.h>
#include <string.h>
#include "validation.c"

void echo(char arg[256]){
	char cmdarg[300];
	int echoReti = validateQuoteArg(arg);

	if (!echoReti){
		strcpy(cmdarg, "echo ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of echo\nUsage: echo \"<comment>\"\n");
	}

}