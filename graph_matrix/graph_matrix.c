#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "graph_matrix.h"
#include "../queue/queue.h"

GraphMatrix create_graph() {
    GraphMatrix graph = (GraphMatrix) malloc(sizeof(_Graph_Matrix));
    for (int i = 0; i < LENGTH; ++i) {
        for (int j = 0; j < LENGTH; ++j) {
            graph->matrix[i][j] = false;
        }
    }
    graph->n_vertex = 0;
    graph->print_graph = print_graph;
    graph->insert_edge = insert_edge;
    graph->is_complete = is_complete;
    graph->insert_vertex = insert_vertex;
    graph->end_graph_matrix = end_graph_matrix;
    return graph;
}

GraphMatrix insert_edge(GraphMatrix graph, int row, int col) {
    if (row > LENGTH - 1 || col > LENGTH - 1) {
        printf("\nPosição inválida!");
        return graph;
    }
    if (graph == NULL) graph = create_graph();

    graph->matrix[row - 1][col - 1] = true;
    graph->matrix[col - 1][row - 1] = true;

    return graph;
}

GraphMatrix insert_vertex(GraphMatrix graph, int qtt) {
    graph->n_vertex = qtt;

    return graph;
}

void print_graph(GraphMatrix graph) {
    if (graph == NULL) {
        printf("Grafo Vazio!");
        return;
    }
    printf("\n    ");
    for (int i = 0; i < graph->n_vertex; ++i) {
        printf("%d_", i + 1);
    }


    for (int i = 0; i < graph->n_vertex; ++i) {
        printf("\n%d | ", i + 1);
        for (int j = 0; j < graph->n_vertex; ++j) {
            printf("%d ", graph->matrix[i][j]);
        }
    }
}

bool is_complete(GraphMatrix graph) {
    for (int i = 0; i < graph->n_vertex; ++i) {
        for (int j = 0; j < graph->n_vertex; ++j) {
            if (i == j && graph->matrix[i][j]) return false;
            if (i != j) {
                if (!graph->matrix[i][j] || graph->matrix[i][j] != graph->matrix[j][i]) return false;
            }
        }
    }
    return true;
}

void end_graph_matrix(GraphMatrix graph) {
    free(graph);
    graph = NULL;
}

void BFS(GraphMatrix graph, int startVertex) {
    bool visited[graph->n_vertex];
    memset(visited, false, sizeof(visited));

    Queue *queue = createQueue(graph->n_vertex);

    visited[startVertex] = true;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d-> ", currentVertex + 1);

        for (int i = 0; i < graph->n_vertex; i++) {
            if (graph->matrix[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }
}



bool visited[LENGTH]; // Array para controlar os vértices visitados

void initVisited(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
}

void DFS(GraphMatrix graph, int vertex) {
    visited[vertex] = true;
    printf("Visitando o vértice: %d\n", vertex+1);

    for (int i = 0; i < graph->n_vertex; i++) {
        if (graph->matrix[vertex][i] && !visited[i]) {
            DFS(graph, i);
        }
    }
}


void dijkstra(GraphMatrix graph, int source) {
    int dist[LENGTH];
    bool sptSet[LENGTH];

    for (int i = 0; i < graph->n_vertex; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < graph->n_vertex - 1; count++) {
        int u, min_distance = INT_MAX;

        for (int v = 0; v < graph->n_vertex; v++) {
            if (!sptSet[v] && dist[v] < min_distance) {
                min_distance = dist[v];
                u = v;
            }
        }

        sptSet[u] = true;

        for (int v = 0; v < graph->n_vertex; v++) {
            if (!sptSet[v] && graph->matrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph->matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->matrix[u][v];
            }
        }
    }

    for (int i = 0; i < graph->n_vertex; i++) {
        printf("Distância de %d para %d: %d\n", source, i, dist[i]);
    }
}
