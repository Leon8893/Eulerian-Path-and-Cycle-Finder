/**
 *  @file user_interface.c
 *  @brief User interface for interacting with the graph collection and finding Eulerian paths or cycles.
 * 
 *  @author Jiri Tesar (xtesar44)
 */

#include "error.h"
#include "graph.h"
#include "euler.h"
#include<stdio.h>
#include<stdlib.h>


void user_interface(GraphCollection_t *graphs) {
    if (graphs == NULL || graphs->graph_count == 0) {
        fprintf(stderr, "Error: No graphs available in the collection.\n");
        return;
    }

    int graph_index;

    while (1) {
        printf("Enter the graph index (1 to %d, or 0 to exit): ", graphs->graph_count);
        scanf("%d", &graph_index);

        if (graph_index == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (graph_index < 1 || graph_index > graphs->graph_count) {
            fprintf(stderr, "Error: Invalid graph index. Please try again.\n");
            continue;
        }

        printf("Selected Graph %d\n", graph_index);

    
        int choice = -1;
        while (choice < 0 || choice > 2) {
            printf("Choose an option:\n");
            printf("1. Find Eulerian Path\n");
            printf("2. Find Eulerian Cycle\n");
            printf("Enter your choice (1 or 2, or 0 to exit): ");
            scanf("%d", &choice);

            if (choice < 0 || choice > 2) {
                fprintf(stderr, "Error: Invalid choice. Please select 1 or 2.\n");
            }

            if (choice == 0) {
                printf("\n");
                return;
            }

            if (choice == 1) {
                int start_vertex, end_vertex;

                printf("You selected Eulerian Path.\n");

                do {
                    printf("Enter the start vertex (1 to %d): ", graphs->graph[graph_index - 1].vertices);
                    scanf("%d", &start_vertex);

                    if (start_vertex < 1 || start_vertex > graphs->graph[graph_index - 1].vertices) {
                        fprintf(stderr, "Error: Start vertex must be between 1 and %d.\n", graphs->graph[graph_index - 1].vertices);
                        continue;
                    }

                    printf("Enter the end vertex (1 to %d): ", graphs->graph[graph_index - 1].vertices);
                    scanf("%d", &end_vertex);

                    if (end_vertex < 1 || end_vertex > graphs->graph[graph_index - 1].vertices) {
                        fprintf(stderr, "Error: End vertex must be between 1 and %d.\n", graphs->graph[graph_index - 1].vertices);
                        continue;
                    }

                    if (start_vertex == end_vertex) {
                        fprintf(stderr, "Error: Start and end vertices must be distinct. Try again.\n");
                    }
                } while (start_vertex == end_vertex || start_vertex < 1 || start_vertex > graphs->graph[graph_index - 1].vertices || end_vertex < 1 || end_vertex > graphs->graph[graph_index - 1].vertices);

                printf("Finding Eulerian Path between vertex %d and vertex %d...\n", start_vertex, end_vertex);

                int odd = odd_vertex(&graphs->graph[graph_index - 1]);
                if (odd != 2) {
                    printf("Graph has no Eulerian Path\n");
                    continue;
                }

                if (vertex_degree(&graphs->graph[graph_index - 1], start_vertex - 1) % 2 != 1 || vertex_degree(&graphs->graph[graph_index - 1], end_vertex - 1) % 2 != 1) {
                    printf("Graph has no Eulerian Path\n");
                    continue;
                }

                find_euler_path(&graphs->graph[graph_index - 1],false, start_vertex - 1, end_vertex - 1);

            } 

            else if (choice == 2) {
                printf("You selected Eulerian Cycle.\n");
                printf("Finding Eulerian Cycle...\n");

                int odd = odd_vertex(&graphs->graph[graph_index - 1]);
                if (odd != 0) {
                    printf("Graph has no Eulerian Cycle\n");
                    continue;
                }

                find_euler_path(&graphs->graph[graph_index - 1], true, 0, 0);
            }       
        }
    }
}


/* end of file user_interface.c */