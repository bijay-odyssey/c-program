#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, int value) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    }
}

int dequeue(CircularQueue *q) {
    if (!isEmpty(q)) {
        int value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        return value;
    }
    return -1;
}

int main() {
    CircularQueue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("%d\n", dequeue(&q));
    return 0;
}
