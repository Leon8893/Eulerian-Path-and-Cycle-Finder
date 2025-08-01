/**
 *  @file euler.c
 *  @brief Implementation of Eulerian path and cycle functionalities.
 * 
 *  @author Jiri Tesar
 */

#include "error.h"
#include "graph.h"
#include "euler.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int vertex_degree(graph_t *graph, int vertex){
    int degree = 0;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj_matrix[vertex][i] > 0) {
            degree++;
        }
    }

    return degree;
}

int odd_vertex(graph_t *graph){
    int odd = 0;

    for (int i = 0; i < graph->vertices; i++) {
        if (vertex_degree(graph, i) % 2 == 1) {
            odd++;
        }
    }

    return odd;
} 


void print_path(path_t *path){
    printf("%d. Path: ",path->pathCount);

    for (int i = 0; i < path->pathIndex; i++) {
        printf("%d ",path->vertices[i] + 1);
    }

    printf("\n");
}


void total_edge(graph_t *graph){
    graph->edges = 0;
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = i + 1; j < graph->vertices; j++) {
            if (graph->adj_matrix[i][j] > 0) {
                graph->edges++;
            }
        }
    }    
}

graph_t graph_copy(graph_t *graph){
    graph_t new_graph;
    new_graph.vertices = graph->vertices;
    new_graph.edges = graph->edges;

    new_graph.adj_matrix = (int **)malloc(new_graph.vertices * sizeof(int *));
    for (int i = 0; i < new_graph.vertices; i++) {
        new_graph.adj_matrix[i] = (int *)malloc(new_graph.vertices * sizeof(int));
    }

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            new_graph.adj_matrix[i][j] = graph->adj_matrix[i][j];
        }
    }

    return new_graph;  
}

void init_path(path_t *path, int count){
    path->vertices = (int *)malloc(count * sizeof(int));
    path->pathIndex = 0;
    path->pathCount = 0;
}

void find_euler_path(graph_t *graph, bool circuit, int start_vertex, int end_vertex){
    graph_t graphcopy = graph_copy(graph);
    path_t path;


    total_edge(graph);

    init_path(&path, graph->edges);

    if (circuit == true) {
        for (int i = 0; i < graph->vertices; i++) {
            path.pathIndex = 0;
            explore_path(i, graph, graphcopy.adj_matrix, &path, 0, circuit, 0, 0);
        }
    }
    
    else {
        
        for (int i = 0; i < graph->vertices; i++) {
            int odd = 0;

            for (int j = 0; j < graph->vertices; j++) {
                if (graph->adj_matrix[i][j] > 0) {
                    odd++;                    
                }
            }
            if (odd % 2 == 1) {
                path.pathIndex = 0;
                explore_path(i, graph, graphcopy.adj_matrix, &path, 0, circuit, start_vertex, end_vertex);
            }
        }
    }

    free_path(&path);
    free_graph(&graphcopy);
}

void explore_path(int vertex, graph_t *graph, int **graphcopy, path_t *path, int edgecount, bool circuit, int start_vertex, int end_vertex){
    path->vertices[path->pathIndex++] = vertex;

    if (circuit == true && edgecount == graph->edges) {
        path->pathCount++;
        print_path(path);
    }

    if (circuit == false && vertex == end_vertex && edgecount == graph->edges) {
        path->pathCount++;
        print_path(path);
    }

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj_matrix[vertex][i] > 0 && graphcopy[vertex][i] > 0) {
            graphcopy[vertex][i] = 0;
            graphcopy[i][vertex] = 0;

            explore_path(i, graph, graphcopy, path, edgecount + 1, circuit, start_vertex, end_vertex);

            graphcopy[vertex][i] = 1;
            graphcopy[i][vertex] = 1;   
        }
    }

    path->pathIndex--;
}

void free_path(path_t *path){
    free(path->vertices);
}

void free_graph(graph_t *graph){
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adj_matrix[i]);
    }

    free(graph->adj_matrix);
}

/* end of file euler.c */