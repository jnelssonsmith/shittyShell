#include <stdio.h>
#include <string.h>

void run(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "./");
	strcat(cmdarg, arg);
	system(cmdarg);
}
