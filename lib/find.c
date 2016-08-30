#include <stdio.h>
#include <string.h>
#include "validation.c"

void find(char arg[256]){
	char cmdarg[300];
	int twoArgReti = validateTwoArgs(arg);

	if (!twoArgReti){
		strcpy(cmdarg, "fgrep -o ");
		strcat(cmdarg, arg);
		strcat(cmdarg, " | wc -l");
		system(cmdarg);
	} else {
		printf("Invalid use of find\nUsage: find <char> <file>\n");
	}


}
