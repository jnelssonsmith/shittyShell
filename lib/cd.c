/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: This implementation makes use of the chdir builtin for c seeing as
a process spawned that uses cd would only have cd changed for that process, then
clear. 
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "validation.c"

void cd(char arg[256]){
	int cdresult;
	char homePath[256];
	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti){
		cdresult = chdir(arg);
		if(cdresult){
			printf("Invalid path or directory\n");
		}
	} else if (!nullArgReti){
		strcpy(homePath, getenv("HOME"));
		cdresult = chdir(homePath);
		if(cdresult){
			printf("Invalid path or directory\n");
		}
	} else {
		printf("Invalid use of cd\nUsage: cd <OPTIONAL: directory>\n");
	}
}
