#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Deque;

void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) return;
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) return -1;
    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return value;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) return -1;
    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return value;
}

int main() {
    Deque dq;
    init(&dq);
    insertRear(&dq, 10);
    insertFront(&dq, 20);
    printf("%d\n", deleteRear(&dq));
    printf("%d\n", deleteFront(&dq));
    return 0;
}
