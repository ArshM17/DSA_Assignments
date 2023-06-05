typedef struct queue{
        int *array;
        int front;
        int rear;
        int size;
        int count;
}queue;

void queueInit(queue* q,int size);

int isEmpty(queue* q);

int isFull(queue* q);

void enqueue(queue* q, int val);

int dequeue(queue* q);

void displayQueue(queue* q);
