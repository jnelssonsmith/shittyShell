#include <stdio.h>
#include <string.h>

void pauseCLI(char input[256]){
	printf("Press enter to continue...");
	fgets(input, 256, stdin);
}
