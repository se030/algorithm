#include <cstdio>
int N, x, nodes = 0, maxHeap[100001];

void insert(int num) {
    int idx = ++nodes;
    maxHeap[idx] = num;
    int parent = idx / 2;
    while (1) {
        if (idx == 1) break;
        if (maxHeap[parent] < num) {
            maxHeap[idx] = maxHeap[parent];
            maxHeap[parent] = num;
            idx = parent;
            parent = parent / 2;
        }
        else break;
    }
}
void pop() {
    if (nodes) {
        printf("%d\n", maxHeap[1]);
        int idx = nodes--;
        maxHeap[1] = maxHeap[idx];
        idx = 1;
        while (1) {
            int left = idx * 2;
            int right = idx * 2 + 1;
            if (nodes < left) return;
            
            int maxVal = maxHeap[left];
            int maxPos = left;
            if (maxVal < maxHeap[right] && right <= nodes) {
                maxVal = maxHeap[right];
                maxPos = right;
            }

            if (maxHeap[idx] < maxVal) {
                maxHeap[maxPos] = maxHeap[idx];
                maxHeap[idx] = maxVal;
                idx = maxPos;
            } else break;
        }
    } else printf("%d\n", 0);
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &x);
        if (x) insert(x);
        else pop();
    }
    return 0;
}