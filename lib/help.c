#include <stdio.h>
#include <string.h>
#include "validation.c"

void help(char arg[256], char originalPath[1024]){
	char cmdarg[1280];
	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);

	strcpy(cmdarg, "more ");
	strcat(cmdarg, originalPath);
	strcat(cmdarg, "/manuals/");
	if (!oneArgReti){
		strcat(cmdarg, arg);
		strcat(cmdarg, ".txt");
		system(cmdarg);
	} else if (!nullArgReti) {
		strcat(cmdarg, "userManual.txt");
		system(cmdarg);
	} else {
		printf("Invalid use of help\nUsage: help <OPTIONAL: command>\n");
	}


}
