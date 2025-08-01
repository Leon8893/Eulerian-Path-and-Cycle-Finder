/**
 *  @file euler.h
 *  @brief Header file for Eulerian path and cycle functionalities.
 * 
 *  @author Jiri Tesar
 */

#ifndef EULER_H
#define EULER_H

#include<stdbool.h>

/**
 * @brief Represents a path in a graph.
 */
typedef struct{
    int *vertices;
    int pathIndex;
    int pathCount;
} path_t;


/**
 * @brief Count of edges in vertex
 * 
 * @param graph Pointer to the graph
 * @param vertex Vertex to be counted
 * 
 * @return int Count of edges
 */
int vertex_degree(graph_t *graph, int vertex);

/**
 * @brief Found odd vertex in graph
 * 
 * @param graph Graph to be initialized
 * 
 * @return int Count of odd vertices
 */
int odd_vertex(graph_t *graph);

/**
 * @brief Print path
 * 
 * @param path Path to be printed
 */
void print_path(path_t *path);

/**
 * @brief Count of edges in graph
 * 
 * @param graph Pointer to the graph
 */
void total_edge(graph_t *graph);

/**
 * @brief Initialize path
 * 
 * @param path Path to be initialized
 * @param count Count of edges
 */
void init_path(path_t *path,int count);

/**
 * @brief Find euler path
 * 
 * @param graph Pointer to the graph
 * @param circuit Circuit or path
 * @param start_vertex Start vertex
 * @param end_vertex End vertex
 */
void find_euler_path(graph_t *graph, bool circuit, int start_vertex, int end_vertex);

/**
 * @brief Copy graph
 * 
 * @param graph Pointer to the graph
 * 
 * @return graph_t Copy of the graph
 */
graph_t graph_copy(graph_t *graph);

/**
 * @brief Explore path
 * 
 * @param vertex Vertex to be explored
 * @param graph Pointer to the graph
 * @param graphcopy Copy of the graph
 * @param path Path to be explored
 * @param edgecount Count of edges
 * @param circuit Circuit or path
 * @param start_vertex Start vertex
 * @param end_vertex End vertex
 */
void explore_path(int vertex, graph_t *graph, int **graphcopy, path_t *path, int edgecount, bool circuit, int start_vertex, int end_vertex);

/**
 * @brief Free path
 * 
 * @param path Path to be freed
 */
void free_path(path_t *path);

/**
 * @brief Free graph
 * 
 * @param graph Graph to be freed
 */
void free_graph(graph_t *graph);

#endif
/* end of file euler.h */