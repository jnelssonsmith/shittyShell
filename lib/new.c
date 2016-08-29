#include <stdio.h>
#include <string.h>

void new(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "touch ");
	strcat(cmdarg, arg);
	system(cmdarg);
}
