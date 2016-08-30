/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
DESCRIPTION: This program serves as a very basic command line interpreter
...

general structure should be:
main clarifies the functions are being passed valid data,
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib/getArgs.c"
#include "lib/cd.c"
#include "lib/clear.c"
#include "lib/cp.c"
#include "lib/dir.c"
#include "lib/echo.c"
#include "lib/find.c"
#include "lib/halt.c"
#include "lib/help.c"
#include "lib/new.c"
#include "lib/pause.c"
#include "lib/quit.c"
#include "lib/run.c"


int main(void){

	char input[256];
	char cmd[256];
	char arg[256];
	char cmdarg[300];
	char* token;
	char* string;
	char* tofree;
	char originalPath[1024];
	char homePath[256];

	getcwd(originalPath, sizeof(originalPath));
	strcpy(homePath, getenv("HOME"));

	do{
		printf("$ ");
		fgets(input, 256, stdin); //use fgets to help prevent buffer overflow
		// fgets n size may need to be changed...
		// fgets adds trailin newline so need to strip
		input[strcspn(input, "\n")] = 0; //more complicated than strtok but threadsafe
		string = strdup(input);

		if(string != NULL){
			tofree = string;
			token = strsep(&string, " ");
			strcpy(cmd, token);
			if(string != NULL){
				strcpy(arg, string); //if only command is present this prevents arg assign from breaking it
			} else {
				strcpy(arg, "");
			}

			free(tofree);

	    }
		//printf("Command: %s\n", cmd);
		//printf("Arg: %s\n", arg);



		if (strcmp(cmd, "quit") == 0){ //cmd is stored with newline included
			quit(arg);

		} else if (strcmp(cmd, "clear") == 0){
			clear(arg);

		} else if (strcmp(cmd, "pause") == 0){
			pauseCLI(arg, input); //have to use pauseCLI as method name since pause is taken

		} else if (strcmp(cmd, "echo") == 0){
			echo(arg);

		} else if (strcmp(cmd, "dir") == 0) {
			dir(arg);

		} else if (strcmp(cmd, "cd") == 0) {
			cd(arg, homePath);

		} else if (strcmp(cmd, "help") == 0){
			help(arg, originalPath);

		} else if (strcmp(cmd, "new") == 0){
			new(arg);

		} else if (strcmp(cmd, "cp") == 0){
			cpCLI(arg);

		} else if (strcmp(cmd, "find") == 0){
			find(arg);

		} else if (strcmp(cmd, "run") == 0){
			run(arg);

		} else if (strcmp(cmd, "halt") == 0){
			halt(arg);

		} else {
			printf("Command: [%s] is not recognized\nType \"help\" for user manual\n", cmd);
		}
	} while(1);

    return 0; //never actually going to reach so idunno if needed...

}
