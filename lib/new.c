/*
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
ARGS:
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void new(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti){
		strcpy(cmdarg, "touch ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of new\nUsage: new <file>\n");
	}

}
