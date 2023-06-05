#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
        int *array;
        int front;
        int rear;
        int size;
        int count;
}queue;

void queueInit(queue* q,int size);

int isEmptyQ(queue* q);

int isFullQ(queue* q);

void enqueue(queue* q, int val);

int dequeue(queue* q);

void displayQueue(queue* q);

#endif
