#include <stdio.h>
#include <string.h>
#include "validation.c"

void cpCLI(char arg[256]){
	char cmdarg[300];
	int twoArgReti = validateTwoArgs(arg);

	if (!twoArgReti){
		strcpy(cmdarg, "cp ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of cp\nUsage: cp <old> <new>\n");
	}

}
