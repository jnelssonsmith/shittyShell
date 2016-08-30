#ifndef _VALIDATION_C_
#define _VALIDATION_C_

#include <regex.h>
#include <stdio.h>
#include <string.h>

int validateNoArgs(char arg[256]){
    if(strcmp(arg, "") == 0){
        return 0;
    } else {
        return 1;
    }
}

int validateOneArg(char arg[256]){
    regex_t oneArgRegex;
    int retiOneArg;
    retiOneArg = regcomp(&oneArgRegex, "^[^ ]+$", REG_EXTENDED);

    if (retiOneArg){
        fprintf(stderr, "Could not compile regex for one arg validation\n");
    	exit(1);
    } else {
        return regexec(&oneArgRegex, arg, 0, NULL, 0);
    }
}

int validateTwoArgs(char arg[256]){
    regex_t twoArgRegex;
    int retiTwoArg;

    retiTwoArg = regcomp(&twoArgRegex, "^[^ ]+ [^ ]+$", REG_EXTENDED);

    if (retiTwoArg){
        fprintf(stderr, "Could not compile regex for two arg validation\n");
    	exit(1);
    } else {
        return regexec(&twoArgRegex, arg, 0, NULL, 0);
    }

}

int validateQuoteArg(char arg[256]){
    regex_t quoteRegex;
    int retiQuote;

    retiQuote = regcomp(&quoteRegex, "^\"((\"*)(.*)(\"*))*\"$", REG_EXTENDED);

    if (retiQuote){
        fprintf(stderr, "Could not compile regex for quote validation\n");
        exit(1);
    } else {
        retiQuote = regexec(&quoteRegex, arg, 0, NULL, 0);
        return retiQuote;
    }
}

#endif
