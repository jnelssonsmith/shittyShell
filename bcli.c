/*
NAME: Joshua Nelsson-Smith
STUDENT ID: 25954113
START DATE: 23/08/16
LAST MODIFIED: 28/08/16
DESCRIPTION: This program serves as a very basic command line interpreter
...
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <errno.h>

int main(void){

	char input[256];
	char cmd[256];
	char arg[256];
	char command[50];
	char cmdarg[300];
	char* token;
	char* string;
	char* tofree;
	regex_t echoRegex;
	regex_t oneArgRegex;
	regex_t twoArgRegex;
	int retiEcho;
	int retiOneArg;
	int retiTwoArg;
	int cdresult;

	retiEcho = regcomp(&echoRegex, "\"((\"*)(.*)(\"*))*\"", REG_EXTENDED);
	retiTwoArg = regcomp(&twoArgRegex, "^[^ ]+ [^ ]+$", REG_EXTENDED);
	if (retiEcho) {
    	fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}
	if (retiTwoArg) {
    	fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}


	do{
		printf("$ ");
		fgets(input, 256, stdin); //use fgets to help prevent buffer overflow
		// fgets n size may need to be changed...
		// fgets adds trailin newline so need to strip
		input[strcspn(input, "\n")] = 0; //more complicated than strtok but threadsafe
		string = strdup(input);

		if(string != NULL){
			tofree = string;
			//maybe strtok is the better function here...
			// seems like best way is to just walk through string and grab correct stuff
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

		if(strcmp(cmd, "quit") == 0){ //cmd is stored with newline included

			exit(0);

		} else if (strcmp(cmd, "clear") == 0){

			system("clear");

		} else if (strcmp(cmd, "pause") == 0){

			printf("Press enter to continue...");
			fgets(input, 256, stdin);

		} else if (strcmp(cmd, "echo") == 0){
			retiEcho = regexec(&echoRegex, arg, 0, NULL, 0);
			if(!retiEcho){
				strcpy(cmdarg, "echo ");
				strcat(cmdarg, arg);
				system(cmdarg);
			} else {
				printf("Invalid argument, please close double quotes \nand use escape quotes or single quotes if need be\n");
			}
			//token = strsep(&string, "\"");


		} else if (strcmp(cmd, "dir") == 0) {
			strcpy(cmdarg, "ls ");
			strcat(cmdarg, arg);
			system(cmdarg);

		} else if (strcmp(cmd, "cd") == 0) {

			cdresult = chdir(arg);
			if(!cdresult){
				//printf("change successful\n");
			} else {
				if(ENOTDIR){
					printf("Invalid path or directory\n");
				}
			}

		} else if (strcmp(cmd, "help") == 0){
			//need to also have null argument show entire user manual
			strcpy(cmdarg, "more manuals/");
			strcat(cmdarg, arg);
			strcat(cmdarg, ".txt");
			system(cmdarg);

		} else if (strcmp(cmd, "new") == 0){
			strcpy(cmdarg, "touch ");
			strcat(cmdarg, arg);
			system(cmdarg);

		} else if (strcmp(cmd, "cp") == 0){
			retiTwoArg = regexec(&twoArgRegex, arg, 0, NULL, 0);
			if(!retiTwoArg){
				//printf("Arg [%s] matched\n", arg);
				strcpy(cmdarg, "cp ");
				strcat(cmdarg, arg);
				system(cmdarg);
			} else {
				printf("Arg [%s] did not match\n", arg);
			}

		} else if (strcmp(cmd, "find") == 0){
			retiTwoArg = regexec(&twoArgRegex, arg, 0, NULL, 0);
			if(!retiTwoArg){
				//printf("Arg [%s] matched\n", arg);
				strcpy(cmdarg, "fgrep -o ");
				strcat(cmdarg, arg);
				strcat(cmdarg, " | wc -l");
				system(cmdarg);

			} else {
				printf("Arg [%s] did not match\n", arg);
			}

		} else if (strcmp(cmd, "run") == 0){
			strcpy(cmdarg, "./");
			strcat(cmdarg, arg);
			system(cmdarg);

		} else if (strcmp(cmd, "halt") == 0){
			strcpy(cmdarg, "pkill ");
			strcat(cmdarg, arg);
			system(cmdarg);

		} else {

			printf("$ command: [%s] is not recognized\n", cmd);
		}
	} while(1);

    return 0; //never actually going to reach so idunno if needed...


}
