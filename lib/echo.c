#include <stdio.h>
#include <string.h>

void echo(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "echo ");
	strcat(cmdarg, arg);
	system(cmdarg);

}
