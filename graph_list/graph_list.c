#include "graph_list.h"

GraphList create_graph_list() {
    GraphList graph = (GraphList) malloc(sizeof(_Graph_List));
    graph->n_edge = 0;
    graph->n_vertex = 0;

    graph->print_graph_list = print_graph_list;
    graph->is_cyclic = is_cyclic;
    graph->insert_edge_list = insert_edge_list;
    graph->insert_vertex_list = insert_vertex_list;
    graph->end_graph_list = end_graph_list;

    return graph;
}

GraphList insert_vertex_list(GraphList *graph, int qtt) {
    if (graph == NULL) graph = (GraphList *) create_graph_list();
    if ((*graph)->n_vertex > LENGTH || (*graph)->n_vertex < 0) {
        printf("\nNúmero de vértices está excedido!");
    }
    for (int i = 0; i < qtt; ++i) {
        (*graph)->vertex[(*graph)->n_vertex].info = (*graph)->n_vertex;
        (*graph)->vertex[(*graph)->n_vertex].next = NULL;
        (*graph)->n_vertex++;
    }
    return (*graph);
}

GraphList *insert_edge_list(GraphList *graph, int source, int target) {
    if ((*graph) == NULL) (*graph) = (GraphList) create_graph_list();

    if ((*graph)->n_vertex < source || (*graph)->n_vertex < target) return (GraphList *) (*graph);
    Node *aux = &(*graph)->vertex[source];
    while (aux->next != NULL) {
        aux = aux->next;
        if (aux->info == target) return (GraphList *) (*graph);
    }
    aux->next = create_node(target);
    (*graph)->n_edge++;
    return (GraphList *) (*graph);
}

void print_graph_list(GraphList graph) {
    if (graph == NULL) {
        printf("Grafo Vazio!\n");
        return;
    }

    printf("\n-----------------------------------------\n");
    printf("Frafo em lista:\n");
    for (int i = 0; i < graph->n_vertex; ++i) {
        Node *aux = &(graph->vertex[i]);

        printf("[%d] -> ", aux->info);

        if (aux->next == NULL) {
            printf("Nenhum vizinho\n");
        } else {
            aux = aux->next;
            while (aux != NULL) {
                printf("%d", aux->info);
                if (aux->next != NULL) {
                    printf(" -> ");
                } else {
                    printf("\n");
                }
                aux = aux->next;
            }
        }
    }
    printf("-----------------------------------------\n");
}


bool dfs(int v, bool visited[], bool recStack[], Node vertex[]) {
    visited[v] = true;
    recStack[v] = true;

    Node *adjNode = vertex[v].next;
    while (adjNode != NULL) {
        int neighbor = adjNode->info;
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack, vertex))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
        adjNode = adjNode->next;
    }

    recStack[v] = false;
    return false;
}

bool is_cyclic(GraphList graph) {
    bool visited[LENGTH];
    bool recStack[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->n_vertex; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, graph->vertex))
                return true;
        }
    }

    return false;
}

void end_graph_list(GraphList graph) {
    free(graph);
    graph = NULL;
}