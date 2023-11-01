#ifndef TREINO_GRAFOS_GRAPH_LIST_H
#define TREINO_GRAFOS_GRAPH_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../node/node.h"

#define LENGTH 10

typedef struct Graph_List {
    int n_vertex;
    Node vertex[LENGTH];
    int n_edge;

    void (*print_graph_list)(struct Graph_List *);

    struct Graph_List **(*insert_edge_list)(struct Graph_List **graph, int source, int target);

    bool (*is_cyclic)(struct Graph_List *graph);

    struct Graph_List *(*insert_vertex_list)(struct Graph_List **graph, int qtt);

    void (*end_graph_list)(struct Graph_List *graph);
} _Graph_List;
typedef _Graph_List *GraphList;

GraphList create_graph_list();

GraphList *insert_edge_list(GraphList *graph, int source, int target);

GraphList insert_vertex_list(GraphList *graph, int qtt);

void print_graph_list(GraphList graph);

bool is_cyclic(GraphList graph);

void end_graph_list(GraphList graph);

#endif //TREINO_GRAFOS_GRAPH_LIST_H
