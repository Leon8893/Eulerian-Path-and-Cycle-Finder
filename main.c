/**
 *  @file main.c
 *  @brief Main entry point for the Eulerian path and cycle application.
 * 
 *  @author Jiri Tesar 
 */

#include "error.h"
#include "graph.h"
#include "euler.h"
#include "user_interface.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    GraphCollection_t graphs;

    load_graph(&graphs, "graph.txt");
    user_interface(&graphs);
    free_graphs(&graphs);
    
    return 0;
}

/* end of file main.c */