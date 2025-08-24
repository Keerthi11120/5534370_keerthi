#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX + 1];   // 1-indexed heap
int heapSize = 0;

// swap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// insert into min-heap
void insert(int x) {
    heap[++heapSize] = x;
    int i = heapSize;
    while (i > 1 && heap[i] < heap[i/2]) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// get min (root)
int getMin() {
    return heap[1];
}

// heapify down
void heapify(int i) {
    int smallest = i;
    int l = 2*i, r = 2*i+1;

    if (l <= heapSize && heap[l] < heap[smallest]) smallest = l;
    if (r <= heapSize && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// delete specific element (lazy way)
void delete(int x) {
    // find element (linear search, but okay since only when delete is called)
    for (int i = 1; i <= heapSize; i++) {
        if (heap[i] == x) {
            heap[i] = heap[heapSize--];  // replace with last element
            heapify(i);                  // fix heap
            break;
        }
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {         // insert
            scanf("%d", &x);
            insert(x);
        } 
        else if (type == 2) {    // delete
            scanf("%d", &x);
            delete(x);
        } 
        else if (type == 3) {    // print min
            printf("%d\n", getMin());
        }
    }
    return 0;
}