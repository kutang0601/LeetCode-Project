#include <stdio.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

// 上浮
void siftUp(int *heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            int tmp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = tmp;
            i = parent;
        } else break;
    }
}

// 下沉
void siftDown(int *heap, int size, int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        int tmp = heap[smallest];
        heap[smallest] = heap[i];
        heap[i] = tmp;
        i = smallest;
    }
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize) {
    KthLargest *obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * (k + 1));
    obj->size = 0;
    obj->k = k;
    for (int i = 0; i < numsSize; i++) {
        // 堆未满直接入堆
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            siftUp(obj->heap, obj->size - 1);
        // 堆已满且新元素更大，替换堆顶
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            siftDown(obj->heap, obj->size, 0);
        }
    }
    return obj;
}

int kthLargestAdd(KthLargest *obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        siftUp(obj->heap, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        siftDown(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest *obj) {
    free(obj->heap);
    free(obj);
}