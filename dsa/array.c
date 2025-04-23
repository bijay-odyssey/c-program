#include <stdio.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int size;
} Array;

void init(Array *a) {
    a->size = 0;
}

void insert(Array *a, int index, int value) {
    if (index < 0 || index > a->size || a->size >= MAX) return;
    for (int i = a->size - 1; i >= index; i--) {
        a->items[i + 1] = a->items[i];
    }
    a->items[index] = value;
    a->size++;
}

void delete(Array *a, int index) {
    if (index < 0 || index >= a->size) return;
    for (int i = index; i < a->size - 1; i++) {
        a->items[i] = a->items[i + 1];
    }
    a->size--;
}

int search(Array *a, int value) {
    for (int i = 0; i < a->size; i++) {
        if (a->items[i] == value) return i;
    }
    return -1;
}

void display(Array *a) {
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->items[i]);
    }
    printf("\n");
}

int main() {
    Array a;
    init(&a);
    insert(&a, 0, 10);
    insert(&a, 1, 20);
    insert(&a, 2, 30);
    display(&a);
    delete(&a, 1);
    display(&a);
    printf("%d\n", search(&a, 30));
    return 0;
}
