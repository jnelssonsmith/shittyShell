/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
originalPath - this is the original path to the shell folder that existed when
the process was created. Because the user can change the working directory, we need
to always know how to reach the manuals folder from root
DESCRIPTION: This command will use less/more to open a specified text file in the
manuals directory, if no command is given it will open the usermanual detailing
the overall use of the the CLI.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void help(char arg[256], char originalPath[1024]){
	char cmdarg[1536];
	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);
	pid_t pid;

	pid = fork();
	if(pid == 0){
		if (!oneArgReti || !nullArgReti){
			/* the following code constructs a path to the relevant manual
			if no arg is given, it automatically opens the userManual.txt file */
			strcpy(cmdarg, originalPath);
			strcat(cmdarg, "/manuals/");
			if (!oneArgReti){
				strcat(cmdarg, arg);
				strcat(cmdarg, ".txt");
				printf("Inside one arg valid %s\n", cmdarg);
			} else if (!nullArgReti) {
				strcat(cmdarg, "userManual.txt");
			}
			/*the use of more or less is defendable here, but I find less to be
			cleaner and more pleasant for the user by not cluttering the console */
			execlp("/usr/bin/less", "less", cmdarg, NULL);
		} else {
			printf("Invalid use of help\nUsage: help <OPTIONAL: command>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}

}
