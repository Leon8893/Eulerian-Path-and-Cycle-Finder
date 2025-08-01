/**
 * @file graph.h
 * @brief Header file for graph data structures and functions.
 *
 * @author Jiri Tesar 
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "error.h"

/**
 * @brief Represents a single graph using an adjacency matrix.
 */
typedef struct {
    int vertices;      // Number of vertices in the graph.
    int edges;         // Number of edges in the graph 
    int **adj_matrix;  // Adjacency matrix representing connections between vertices.
} graph_t;

/**
 * @brief Represents a collection of graphs.
 */
typedef struct {
    int graph_count;  // Total number of graphs in the collection.
    graph_t *graph;   // Array of graphs in the collection.
} GraphCollection_t;

/**
 * @brief Initializes a graph with the given number of vertices.
 *
 * @param graph Pointer to the graph structure to initialize.
 * @param vertices Number of vertices in the graph.
 */
void init_graph(graph_t *graph, int vertices);

/**
 * @brief Loads graphs from a file with validation.
 *
 * @param graphs Pointer to the graph collection to populate.
 * @param filename Path to the input file containing graph data.
 */
void load_graph(GraphCollection_t *graphs, const char *filename);

/**
 * @brief Validates that the adjacency matrix contains only binary values (0 or 1).
 *
 * @param graph Pointer to the graph structure to validate.
 * @return 1 if the matrix is valid, 0 otherwise.
 */
int validate_adjacency_matrix(graph_t *graph);

/**
 * @brief Prints the adjacency matrix of the graph to stdout.
 * 
 * @param graph Pointer to the graph to print.
 */
void print_graph(graph_t *graph);

/**
 * @brief Frees the allocated memory of a graph.
 *
 * @param graph Pointer to the graph structure to clean up.
 */
void free_graphs(GraphCollection_t *graphs);

#endif
/* end of file graph.h */