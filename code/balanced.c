#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RDparser.h"

int main(int argc, char* argv[]) {
    assert(argv[1]); //to hold the terminal characters of the grammar
    assert(argv[2]); //to hold the input string
    token *tok = init_tokens(argv[2]);
    if(!tok){
        printf("could not allocate memory to token members");
    }
    parse(tok, argv[1]);
    free(tok);
}
