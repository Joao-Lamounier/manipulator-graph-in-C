#include <stdio.h>
#include "graph_matrix/graph_matrix.h"
#include "graph_list/graph_list.h"
#include "utils/utils.h"

void designate_op(int op, GraphMatrix graph_m, GraphList *graph_l);

int main() {
    GraphMatrix graph_m = create_graph();
    GraphList graph_l = create_graph_list();
    color(5);
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║");
    color(7);
    printf("                             Bem-vindo ao                             ");
    color(5);
    printf("║\n║");
    color(7);
    printf("                          Simulador de Grafos                         ");
    color(5);
    printf("║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝");
    printf("\n│");
    color(7);
    printf("* Para iniciar selecione uma opção;;                                  ");
    color(5);
    printf("│\n│");
    color(7);
    printf("* Para finalizar pressione o dígito '6';                              ");
    color(5);
    printf("│");
    printf("\n└──────────────────────────────────────────────────────────────────────┘\n");

    color(7);

    int op = 0;
    do {
        printf("\n1. Insere dados do grafo (matriz e lista de adjacência)");
        printf("\n2. Mostre qual melhor armazenamento para grafo de entrada");
        printf("\n3. Verifique se o grafo é completo");
        printf("\n4. Verificar se o grafo é cíclico");
        printf("\n5. Mostrar Grafo");
        printf("\n6. Busca por profundidade");
        printf("\n7. Busca por largura");
        printf("\n8. Finalizar");
        printf("\nMostrar distâncias");
        printf("\n-> ");
        scanf("%d", &op);
        designate_op(op, graph_m, &graph_l);
    } while (op != 8);

    return 0;
}

void designate_op(int op, GraphMatrix graph_m, GraphList *graph_l) {
    switch (op) {
        case 1: {
            if (graph_m->n_vertex == 0) {
                int qtt = collect_int();
                (*graph_l)->insert_vertex_list(graph_l, qtt);
                graph_m->insert_vertex(graph_m, qtt);
            }
            int x = 0, y = 0;
            printf("\nInsira os vertices (x, y) para adicionar a aresta: ");
            printf("\nx-> ");
            scanf("%d", &x);
            printf("\ny-> ");
            scanf("%d", &y);
            graph_m->insert_edge(graph_m, x, y);
            (*graph_l)->insert_edge_list(graph_l, x, y);

            break;
        }
        case 2:
            best_representation((*graph_l)->n_vertex, (*graph_l)->n_edge);
            break;
        case 3:
            if (graph_m->is_complete(graph_m)) {
                printf("\nÉ completo!");
            } else printf("\nNão completo!");
            break;

        case 4:
            if (is_cyclic((*graph_l))) {
                printf("\nÉ ciclico!");
            } else printf("\nNão é cíclico!");
            break;

        case 5:
            graph_m->print_graph(graph_m);
            (*graph_l)->print_graph_list((*graph_l));
            break;
        case 6:{
            int info;
            printf("Insira o vertice a ser iniciado: ");
            scanf("%d", &info);
            DFS(graph_m, info-1);
            break;
        }
        case 7:{
            int info;
            printf("Insira o vertice a ser iniciado: ");
            scanf("%d", &info);
            BFS(graph_m, info-1);
            break;
        }
        case 8:
            (*graph_l)->end_graph_list((*graph_l));
            graph_m->end_graph_matrix(graph_m);
            break;
        case 9: {
            int info;
            printf("Insira o vertice a ser iniciado: ");
            scanf("%d", &info);
            dijkstra(graph_m, info - 1);
            break;
        }
        default:
            printf("\nOpção inválida!");
    }
}
