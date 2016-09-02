/*
START DATE: 25/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: A group of validation functions for the purposes of validating the
arguments string passed to each of the terminal functions. The validation works
via regular expressions, each function returns 0 if there is a match, or 1 if
the arg did not match the regex.
*/

//need to use guards to prevent redfinition errors from multiple imports
#ifndef _VALIDATION_C_
#define _VALIDATION_C_


#include <regex.h>
#include <stdio.h>
#include <string.h>

/* validateNoArgs doesn't need a regex as it's fairly simple, just check if
the arg string is equal to the empty string, if it is, return a match (0) or
if not, return not a match (1) */
int validateNoArgs(char arg[256]){
    if(strcmp(arg, "") == 0){
        return 0;
    } else {
        return 1;
    }
}
/* validateOneArg regex checks for no spaces or tabs so you know there is only
one string entered */
int validateOneArg(char arg[256]){
    regex_t oneArgRegex;
    int retiOneArg;
    retiOneArg = regcomp(&oneArgRegex, "^[^ ,\t]+$", REG_EXTENDED);

    // if the regex doesnt compile successfully, print error message and exit
    if (retiOneArg){
        fprintf(stderr, "Could not compile regex for one arg validation\n");
    	exit(1);
    } else {
        // checks arg against regex and returns 1 if no match and 0 if match
        return regexec(&oneArgRegex, arg, 0, NULL, 0);
    }
}

/* validateTwoArgs regex checks for a string then a space, then another string.
This therefore can check against whether the arg string is of the form
"[arg] [arg]". The space is important because thats how we feed it to the system
function for accurate exectution */
int validateTwoArgs(char arg[256]){
    regex_t twoArgRegex;
    int retiTwoArg;

    retiTwoArg = regcomp(&twoArgRegex, "^[^ ,\t]+ [^ ,\t]+$", REG_EXTENDED);

    if (retiTwoArg){
        fprintf(stderr, "Could not compile regex for two arg validation\n");
    	exit(1);
    } else {
        return regexec(&twoArgRegex, arg, 0, NULL, 0);
    }

}

/* this function is specifically for the echo function but it could be useful
for other functions in future. It ensures that the argument string is of the form
"some comment in here" because we define a comment in the spec as needing to start
and end with double quotes. The regex also checks for and allows the use of escape
quotes so the user can still use quotes in their string as needed */
int validateQuoteArg(char arg[256]){
    regex_t quoteRegex;
    int retiQuote;
    /* the echo regex checks that it starts and ends with a quote, this regex
    does not support escape quotes, but a user can use single quotes instead */
    retiQuote = regcomp(&quoteRegex, "^\"[^\"]*\"$", REG_EXTENDED);

    if (retiQuote){
        fprintf(stderr, "Could not compile regex for quote validation\n");
        exit(1);
    } else {
        return regexec(&quoteRegex, arg, 0, NULL, 0);
    }
}

#endif
