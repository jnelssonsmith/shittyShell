#include <stdio.h>
#include <string.h>
#include "validation.c"

void whereami(char arg[256]){
	char cmdarg[300];
	int nullArgReti = validateNoArgs(arg);

	if (!nullArgReti){
		system("pwd");
	} else {
		printf("Invalid use of whereami\nUsage: whereami [NO ARGS]\n");
	}
}