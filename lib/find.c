#include <stdio.h>
#include <string.h>

void find(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "fgrep -o ");
	strcat(cmdarg, arg);
	strcat(cmdarg, " | wc -l");
	system(cmdarg);
}
