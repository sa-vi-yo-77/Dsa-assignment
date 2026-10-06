#include <stdio.h>

#define K 3
#define MAX 20

typedef struct {
    int value;
    int list;
    int index;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;
long long comparisons = 0;
long long swaps = 0;

int lessNode(HeapNode a, HeapNode b) {
    comparisons++;
    return a.value < b.value;
}

void swapNode(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void siftUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) / 2;
        if (!lessNode(heap[pos], heap[parent]))
            break;
        swapNode(&heap[pos], &heap[parent]);
        pos = parent;
    }
}

void siftDown(int pos) {
    while (1) {
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;
        int smallest = pos;

        if (left < heapSize && lessNode(heap[left], heap[smallest]))
            smallest = left;

        if (right < heapSize && lessNode(heap[right], heap[smallest]))
            smallest = right;

        if (smallest == pos)
            break;

        swapNode(&heap[pos], &heap[smallest]);
        pos = smallest;
    }
}

void insertNode(HeapNode node) {
    heap[heapSize] = node;
    heapSize++;
    siftUp(heapSize - 1);
}

HeapNode removeMin(void) {
    HeapNode minNode = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    if (heapSize > 0)
        siftDown(0);

    return minNode;
}

void printHeap(void) {
    int i;
    printf("Heap: ");
    if (heapSize == 0) {
        printf("Empty");
    } else {
        for (i = 0; i < heapSize; i++)
            printf("%d ", heap[i].value);
    }
    printf("
");
}

int main(void) {
    int lists[K][4] = {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    int size[K] = {4, 4, 4};
    int output[K * 4];
    int outIndex = 0;
    int i;

    for (i = 0; i < K; i++) {
        HeapNode node = {lists[i][0], i, 0};
        insertNode(node);
    }

    printf("K-WAY MERGE USING MIN HEAP
");
    printf("Initial ");
    printHeap();

    while (heapSize > 0) {
        HeapNode minNode = removeMin();
        output[outIndex++] = minNode.value;

        if (minNode.index + 1 < size[minNode.list]) {
            HeapNode nextNode;
            nextNode.list = minNode.list;
            nextNode.index = minNode.index + 1;
            nextNode.value = lists[minNode.list][nextNode.index];
            insertNode(nextNode);
        }

        if (heapSize > 0) {
            printf("After removing %d: ", minNode.value);
            printHeap();
        } else {
            printf("After removing %d: Heap Empty
", minNode.value);
        }
    }

    printf("
Merged output: ");
    for (i = 0; i < outIndex; i++)
        printf("%d ", output[i]);

    printf("

Key comparisons: %lld", comparisons);
    printf("
Heap swaps: %lld
", swaps);

    return 0;
}
