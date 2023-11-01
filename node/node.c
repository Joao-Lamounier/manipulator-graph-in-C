#include "node.h"

Node *create_node(int info) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->info = info;
    node->next = NULL;

    return node;
}