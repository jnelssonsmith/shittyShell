/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 23/08/16
LAST MODIFIED: 29/08/16
DESCRIPTION: This program serves as a very basic command line interpreter
...

general structure should be:
main clarifies the functions are being passed valid data,
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <errno.h>
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
#include "lib/validation.c"

int main(void){

	char input[256];
	char cmd[256];
	char arg[256];
	char cmdarg[300];
	char* token;
	char* string;
	char* tofree;
	int nullArgReti;
	int oneArgReti;
	int twoArgReti;
	int echoReti;
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

		int nullArgReti = validateNoArgs(arg);
		int oneArgReti = validateOneArg(arg);
		int twoArgReti = validateTwoArgs(arg);
		int echoReti = validateQuoteArg(arg);


		if (strcmp(cmd, "quit") == 0){ //cmd is stored with newline included
			if(!nullArgReti){
				quit();
			} else {
				printf("Invalid use of quit\nUsage: quit [no arguments]\n");
			}


		} else if (strcmp(cmd, "clear") == 0){
			if(!nullArgReti){
				clear();
			} else {
				printf("Invalid use of clear\nUsage: clear [no arguments]\n");
			}

		} else if (strcmp(cmd, "pause") == 0){
			if(!nullArgReti){
				pauseCLI(input); //have to use pauseCLI as method name since pause is taken
			} else {
				printf("Invalid use of pause\nUsage: pause [no arguments]\n");
			}

		} else if (strcmp(cmd, "echo") == 0){
			if (!echoReti){
				echo(arg);
			} else {
				printf("Invalid use of echo\nUsage: echo \"<comment>\"\n");
			}

		} else if (strcmp(cmd, "dir") == 0) {
			if (!oneArgReti || !nullArgReti){
				dir(arg);
			} else {
				printf("Invalid use of dir\nUsage: dir <OPTIONAL: directory>\n");
			}


		} else if (strcmp(cmd, "cd") == 0) {
			if (!oneArgReti){
				cd(arg);
			} else if (!nullArgReti){
				cd(homePath);
			} else {
				printf("Invalid use of cd\nUsage: cd <OPTIONAL: directory>\n");
			}

		} else if (strcmp(cmd, "help") == 0){
			if (!oneArgReti || !nullArgReti){
				help(arg, originalPath);
			} else {
				printf("Invalid use of help\nUsage: help <OPTIONAL: command>\n");
			}


		} else if (strcmp(cmd, "new") == 0){
			if (!oneArgReti){
				new(arg);
			} else {
				printf("Invalid use of new\nUsage: new <file>\n");
			}

		} else if (strcmp(cmd, "cp") == 0){
			if (!twoArgReti){
				cpCLI(arg);
			} else {
				printf("Invalid use of cp\nUsage: cp <old> <new>\n");
			}

		} else if (strcmp(cmd, "find") == 0){
			if (!twoArgReti){
				find(arg);
			} else {
				printf("Invalid use of find\nUsage: find <char> <file>\n");
			}

		} else if (strcmp(cmd, "run") == 0){
			if (!oneArgReti){
				run(arg);
			} else {
				printf("Invalid use of run\nUsage: run <program>\n");
			}

		} else if (strcmp(cmd, "halt") == 0){
			if (!oneArgReti){
				halt(arg);
			} else {
				printf("Invalid use of halt\nUsage: halt <program>\n");
			}

		} else {
			printf("Command: [%s] is not recognized\nType \"help\" for user manual\n", cmd);
		}
	} while(1);

    return 0; //never actually going to reach so idunno if needed...


}
