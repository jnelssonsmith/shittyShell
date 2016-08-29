#include <stdio.h>
#include <string.h>

void halt(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "pkill ");
	strcat(cmdarg, arg);
	system(cmdarg);
}
