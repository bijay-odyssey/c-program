#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int size;
} PriorityQueue;

void init(PriorityQueue *pq) {
    pq->size = 0;
}

void enqueue(PriorityQueue *pq, int value) {
    if (pq->size == MAX) return;
    int i = pq->size - 1;
    while (i >= 0 && pq->items[i] < value) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }
    pq->items[i + 1] = value;
    pq->size++;
}

int dequeue(PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    return pq->items[--pq->size];
}

int main() {
    PriorityQueue pq;
    init(&pq);
    enqueue(&pq, 30);
    enqueue(&pq, 50);
    enqueue(&pq, 10);
    printf("%d\n", dequeue(&pq));
    return 0;
}
