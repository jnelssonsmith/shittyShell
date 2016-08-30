/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 23/08/16
LAST MODIFIED: 30/08/16
DESCRIPTION: This program serves as a very basic command line interpreter
...

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
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

	/* get the current working directory path, this is necessary due to our
	implementation of help, see the lib/help.c file for more information */
	getcwd(originalPath, sizeof(originalPath)); //need to keep original path saved so we can reference user manuals

	/* we save the home path so we can access it for the purposes of cd,
	see the lib/cd.c file for more information */
	strcpy(homePath, getenv("HOME")); //need to have the home path saved to feed to the cd function

	/* The following loop serves as an infinite loop until the user types quit,
	the loop reads in user input and then splits the user input into a cmd string
	and an arg string. It then tries to match the cmd string against the list of
	known commands, and if it cant find it, displays an error message. If the cmd
	does match, it feeds the arg to that commands handling function. Look in the
	lib folder of this directory for each command's file for further implementation
	details */
	do{
		printf("$ ");
		fgets(input, 256, stdin); //use fgets to help prevent buffer overflow
		/* Note that fgets will also read in the \n from the user pressing enter
		so need to strip trailing newline*/
		input[strcspn(input, "\n")] = 0; //strip newline, more complicated than strtok but threadsafe
		string = strdup(input);

		if(string != NULL){
			tofree = string;
			token = strsep(&string, " "); //grabs out the command part from input
			strcpy(cmd, token);
			if(string != NULL){
				strcpy(arg, string); //if there is more than just a command grab it into the arg
			} else {
				strcpy(arg, "");
			}

			free(tofree);
	    }

		if (strcmp(cmd, "quit") == 0){
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
			cpCLI(arg); //have to use cpCLI as method name since cp is taken

		} else if (strcmp(cmd, "find") == 0){
			find(arg);

		} else if (strcmp(cmd, "run") == 0){
			run(arg);

		} else if (strcmp(cmd, "halt") == 0){
			halt(arg);

		} else {
			printf("Command: [%s] is not recognized\nType \"help\" for user manual\n", cmd);
		}
	} while(1); //loop forever

    return 0; //never actually going to reach but following int main() convention

}
