#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "validation.c"

void cd(char arg[256], char homePath[256]){
	int cdresult;

	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti){
		cdresult = chdir(arg);
		if(cdresult){
			printf("Invalid path or directory\n");
		}
	} else if (!nullArgReti){
		cdresult = chdir(homePath);
		if(cdresult){
			printf("Invalid path or directory\n");
		}
	} else {
		printf("Invalid use of cd\nUsage: cd <OPTIONAL: directory>\n");
	}
}