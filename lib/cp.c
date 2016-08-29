#include <stdio.h>
#include <string.h>

void cpCLI(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "cp ");
	strcat(cmdarg, arg);
	system(cmdarg);
}
