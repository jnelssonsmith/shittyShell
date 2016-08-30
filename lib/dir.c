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
