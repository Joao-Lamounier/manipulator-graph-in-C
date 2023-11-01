#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
} Queue;

Queue *createQueue(int capacity);

bool isFull(Queue *queue);

bool isEmpty(Queue *queue);

void enqueue(Queue *queue, int item);

int dequeue(Queue *queue);

#endif //UNTITLED1_QUEUE_H
