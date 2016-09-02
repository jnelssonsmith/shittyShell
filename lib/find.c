/*
START DATE: 25/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: Find uses the fgrep command to count the occurences of a phrase
based in a line, then this is piped into a line count to check accross every

*/

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
