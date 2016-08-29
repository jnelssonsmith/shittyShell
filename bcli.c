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
	void echo();
	void cd();
	void quit();
	void clear();
	void pauseCLI();
	void dir();
	void help();
	void new();
	void cpCLI();
	void find();
	void run();
	void halt();

	retiEcho = regcomp(&echoRegex, "^\"((\"*)(.*)(\"*))*\"$", REG_EXTENDED);
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
			quit();

		} else if (strcmp(cmd, "clear") == 0){
			clear();

		} else if (strcmp(cmd, "pause") == 0){
			pauseCLI(input); //have to use pauseCLI as method name since pause is taken
			//printf("Press enter to continue...");
			//fgets(input, 256, stdin);

		} else if (strcmp(cmd, "echo") == 0){
			retiEcho = regexec(&echoRegex, arg, 0, NULL, 0);
			if(!retiEcho){
				echo(arg);
			} else {
				printf("Invalid argument, please close double quotes \nand use escape quotes or single quotes if need be\n");
			}
			//token = strsep(&string, "\"");


		} else if (strcmp(cmd, "dir") == 0) {
			dir(arg);

		} else if (strcmp(cmd, "cd") == 0) {
			cd(arg);


		} else if (strcmp(cmd, "help") == 0){
			//need to also have null argument show entire user manual
			help(arg);

		} else if (strcmp(cmd, "new") == 0){
			new(arg);

		} else if (strcmp(cmd, "cp") == 0){
			retiTwoArg = regexec(&twoArgRegex, arg, 0, NULL, 0);
			if(!retiTwoArg){
				//printf("Arg [%s] matched\n", arg);
				cpCLI(arg);
			} else {
				printf("Arg [%s] did not match\n", arg);
			}

		} else if (strcmp(cmd, "find") == 0){
			retiTwoArg = regexec(&twoArgRegex, arg, 0, NULL, 0);
			if(!retiTwoArg){
				//printf("Arg [%s] matched\n", arg);
				find(arg);

			} else {
				printf("Arg [%s] did not match\n", arg);
			}

		} else if (strcmp(cmd, "run") == 0){
			run(arg);

		} else if (strcmp(cmd, "halt") == 0){
			halt(arg);

		} else {

			printf("$ command: [%s] is not recognized\n", cmd);
		}
	} while(1);

    return 0; //never actually going to reach so idunno if needed...


}

void echo(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "echo ");
	strcat(cmdarg, arg);
	system(cmdarg);

}

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

void quit(void){
	exit(0);
}

void clear(void){
	system("clear");
}

void pauseCLI(char input[256]){
	printf("Press enter to continue...");
	fgets(input, 256, stdin);
}

void dir(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "ls ");
	strcat(cmdarg, arg);
	system(cmdarg);

}

void help(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "more manuals/");
	strcat(cmdarg, arg);
	strcat(cmdarg, ".txt");
	system(cmdarg);
}

void new(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "touch ");
	strcat(cmdarg, arg);
	system(cmdarg);
}


void cpCLI(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "cp ");
	strcat(cmdarg, arg);
	system(cmdarg);
}

void find(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "fgrep -o ");
	strcat(cmdarg, arg);
	strcat(cmdarg, " | wc -l");
	system(cmdarg);
}

void run(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "./");
	strcat(cmdarg, arg);
	system(cmdarg);
}

void halt(char arg[256]){
	char cmdarg[300];
	strcpy(cmdarg, "pkill ");
	strcat(cmdarg, arg);
	system(cmdarg);
}
