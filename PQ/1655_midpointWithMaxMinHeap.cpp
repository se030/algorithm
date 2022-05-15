#include <cstdio>
#include <queue>
using namespace std;
int N, num;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
void sol(int num, int idx) {
    if (idx == 0) maxHeap.push(num);
    else {
        if (num < maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if (!(idx % 2)) {
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else if (maxHeap.size() != minHeap.size()) {
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    printf("%d\n", maxHeap.top());
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        sol(num, i);
    }
    return 0;
}