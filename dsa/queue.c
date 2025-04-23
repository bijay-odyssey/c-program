#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front++];
    }
    return -1;
}

int peek(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[q->front];
    }
    return -1;
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d\n", dequeue(&q));
    printf("%d\n", peek(&q));
    return 0;
}
