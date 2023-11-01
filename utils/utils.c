#include "utils.h"

int collect_int() {
    printf("\nQuantos vertices deseja no grafo?");
    int n_vertex;
    scanf("%d", &n_vertex);
    if (n_vertex > LENGTH || n_vertex < 0) {
        printf("\nQuantidade inválida");
        return 0;
    }
    return n_vertex;
}


void best_representation(int n_vertex, int n_edge) {
    int size_matrix = n_vertex * n_vertex;
    int size_list = n_vertex + n_edge;


    if (size_list < size_matrix) {
        printf("\nLista é a melhor opção");
    } else {
        printf("\nMatriz é a melhor opção");
    }
}


void color(int _color) {
    switch (_color) {
        case 0:
            printf(ANSI_COLOR_BLACK);
            break;
        case 1:
            printf(ANSI_COLOR_RED);
            break;
        case 2:
            printf(ANSI_COLOR_GREEN);
            break;
        case 3:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 4:
            printf(ANSI_COLOR_BLUE);
            break;
        case 5:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case 6:
            printf(ANSI_COLOR_CYAN);
            break;
        case 7:
            printf(ANSI_COLOR_WHITE);
            break;
        default:
            printf(ANSI_COLOR_RESET);
            break;
    }
}