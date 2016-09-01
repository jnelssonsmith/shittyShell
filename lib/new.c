/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "validation.c"

void new(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);
	int pid;
	char prePath[1024];
	FILE *newFile;

	if (!oneArgReti){
		getcwd(prePath, sizeof(prePath));
		strcat(cmdarg, prePath);
		strcat(cmdarg, "/");
		strcat(cmdarg, arg);
		newFile = fopen(cmdarg, "w");
		fclose(newFile);

	} else {
		printf("Invalid use of new\nUsage: new <file>\n");
	}

}
