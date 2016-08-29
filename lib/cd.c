#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void cd(char arg[256]){
	int cdresult;

	cdresult = chdir(arg);
	if(!cdresult){
		//printf("change successful\n");
	} else {
		if(ENOTDIR){
			printf("Invalid path or directory\n");
		}
	}
}
