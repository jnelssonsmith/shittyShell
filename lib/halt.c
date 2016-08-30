/*
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
ARGS:
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void halt(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti){
		strcpy(cmdarg, "pkill ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of halt\nUsage: halt <program>\n");
	}

}
