/**
 * @file error.h
 * @brief Header file for error handling functionality.
 *
 * @author Jiri Tesar 
 */

#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

/**
 * @brief Enumeration of error codes used across the application.
 */
typedef enum {
    ERROR_MEMORY_ALLOC,      // Memory allocation failure.
    ERROR_FILE_OPEN,         // File opening issue.
    ERROR_INVALID_INPUT,     // Provided input does not meet expected format or constraints.
    ERROR_GRAPH_LOAD,        // Error during graph loading (e.g., invalid file format).
    ERROR_GRAPH_EMPTY        // Operation attempted on an empty or uninitialized graph.
} error_t;

/**
 * @brief Prints a descriptive error message and exits the program.
 *
 * @param error Error code to be printed.
 */
void print_error(error_t error);

/**
 * @brief Global variable for tracking the last occurred error.
 */
extern error_t error; 

#endif 
/* end of file error.h */