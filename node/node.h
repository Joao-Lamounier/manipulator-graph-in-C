#ifndef TREINO_GRAFOS_NODE_H
#define TREINO_GRAFOS_NODE_H

#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *next;
} Node;

Node *create_node(int info);


#endif //TREINO_GRAFOS_NODE_H
