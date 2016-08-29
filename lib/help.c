#include <stdio.h>
#include <string.h>

void help(char arg[256], char originalPath[1024]){
	char cmdarg[1280];
	int error;

	strcpy(cmdarg, "more ");
	strcat(cmdarg, originalPath);
	strcat(cmdarg, "/manuals/");
	if (strcmp(arg, "") == 0){
		strcat(cmdarg, "userManual");
	} else {
		strcat(cmdarg, arg);
	}
	strcat(cmdarg, ".txt");
	system(cmdarg);
}
