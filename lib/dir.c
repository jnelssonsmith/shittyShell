#include <stdio.h>
#include <string.h>

void dir(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "ls ");
	strcat(cmdarg, arg);
	system(cmdarg);

}
