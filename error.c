/**
 * @file error.c
 * @brief Implementation of error handling functionality.
 * 
 * @author Jiri Tesar 
 */

#include "error.h"
#include <stdio.h>
#include <stdlib.h>

error_t error = 0;

static const char *error_messages[] = {
    "Memory allocation error",
    "File opening error",
    "Invalid input error",
    "Error while loading graph",
    "Empty graph error"
};

void print_error(error_t error) {
    if (error < 0 || error >= sizeof(error_messages) / sizeof(error_messages[0])) {
        fprintf(stderr, "Unknown error\n");
    } 

    else {
        fprintf(stderr, "Error: %s\n", error_messages[error]);
    }
    
    exit(error);
}

/* end of file error.c */