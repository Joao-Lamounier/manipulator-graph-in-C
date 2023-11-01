#ifndef TREINO_GRAFOS_GRAPH_MATRIX_H
#define TREINO_GRAFOS_GRAPH_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10

typedef struct Graph_Matrix {
    bool matrix[LENGTH][LENGTH];
    int n_vertex;

    void (*print_graph)(struct Graph_Matrix *);


    struct Graph_Matrix *(*insert_edge)(struct Graph_Matrix *graph, int row, int col);

    bool (*is_complete)(struct Graph_Matrix *);

    struct Graph_Matrix *(*insert_vertex)(struct Graph_Matrix *graph, int qtt);

    void (*end_graph_matrix)(struct Graph_Matrix *graph);
} _Graph_Matrix;
typedef _Graph_Matrix *GraphMatrix;

GraphMatrix create_graph();

GraphMatrix insert_edge(GraphMatrix graph, int row, int col);

GraphMatrix insert_vertex(GraphMatrix graph, int qtt);

void print_graph(GraphMatrix graph);

void category_graph(GraphMatrix graph);

void graph_directed(GraphMatrix graph);

int vertex_degree(GraphMatrix graph, int vertex);

bool is_complete(GraphMatrix graph);

void end_graph_matrix(GraphMatrix graph);

void BFS(GraphMatrix graph, int startVertex);

void DFS(GraphMatrix graph, int vertex);

void dijkstra(GraphMatrix graph, int source);

#endif //TREINO_GRAFOS_GRAPH_MATRIX_H