/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void dir(char arg[256]){
	char cmdarg[300];
	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti || !nullArgReti){
		strcpy(cmdarg, "ls ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of dir\nUsage: dir <OPTIONAL: directory>\n");
	}

}
