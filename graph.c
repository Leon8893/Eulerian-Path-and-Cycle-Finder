/**
 * @file graph.c
 * @brief Implementation of graph-related functionalities.
 *
 * @author Jiri Tesar
 */

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(graph_t *graph, int vertices) {
    graph->vertices = vertices;
    graph->adj_matrix = (int **)malloc(vertices * sizeof(int *));
    if (!graph->adj_matrix) {
        error = ERROR_MEMORY_ALLOC;
        print_error(error);
    }

    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = (int *)calloc(vertices, sizeof(int));
        if (!graph->adj_matrix[i]) {
            error = ERROR_MEMORY_ALLOC;
            print_error(error);
        }
    }
}

int validate_graph_count(int expected_count, int actual_count) {
    if (expected_count != actual_count) {
        printf("Mismatch in number of graphs: expected %d, found %d.\n", expected_count, actual_count);
        return 0;
    }
    return 1;
}


int validate_adjacency_matrix(graph_t *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj_matrix[i][j] != 0 && graph->adj_matrix[i][j] != 1) {
                fprintf(stderr, "Invalid value in adjacency matrix at [%d][%d]\n", i, j);
                return 0;
            }
        }
    }
    return 1;
}

void load_graph(GraphCollection_t *graphs, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        error = ERROR_FILE_OPEN;
        print_error(error);
        return;
    }

    int graph_count = 0;
    if (fscanf(file, "%d", &graph_count) != 1 || graph_count <= 0) {
        error = ERROR_INVALID_INPUT;
        print_error(error);
        fclose(file);
        return;
    }

    graphs->graph_count = graph_count;
    graphs->graph = (graph_t *)malloc(graph_count * sizeof(graph_t));
    if (!graphs->graph) {
        error = ERROR_MEMORY_ALLOC;
        print_error(error);
        fclose(file);
        return;
    }

    for (int g = 0; g < graph_count; g++) {
        int vertices = 0;
        if (fscanf(file, "%d", &vertices) != 1 || vertices <= 0) {
            error = ERROR_INVALID_INPUT;
            print_error(error);
            fclose(file);
            return;
        }

        init_graph(&graphs->graph[g], vertices);

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                int value = -1;
                if (fscanf(file, "%d", &value) != 1 || (value != 0 && value != 1)) {
                    error = ERROR_INVALID_INPUT;
                    print_error(error);
                    fclose(file);
                    return;
                }
                graphs->graph[g].adj_matrix[i][j] = value;
            }
        }
    }

    fclose(file);
}

void print_graph(graph_t *graph) {
    if (!graph || !graph->adj_matrix) {
        error = ERROR_GRAPH_EMPTY;
        print_error(error);
        return;
    }

    printf("Adjacency Matrix (%d vertices):\n", graph->vertices);
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void free_graphs(GraphCollection_t *graphs) {
    for (int i = 0; i < graphs->graph_count; i++) {
        for (int j = 0; j < graphs->graph[i].vertices; j++) {
            free(graphs->graph[i].adj_matrix[j]);
        }
        free(graphs->graph[i].adj_matrix);
    }
    free(graphs->graph);
}

/* end of file graph.c */