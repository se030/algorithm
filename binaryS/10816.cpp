#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, M, *cards, *target;
int upper(int num) {
    int lo = 0, hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (cards[mid] <= num) lo = mid;
        else hi = mid;
    }
    return cards[hi] == num? hi + 1 : hi;
}
int lower(int num) {
    int lo = 0, hi = N;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (num <= cards[mid]) hi = mid;
        else lo = mid;
    }
    return cards[lo] == num? lo - 1 : lo;
}

int main() {
    scanf("%d", &N);
    cards = (int*) malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) scanf("%d", &cards[i]);
    sort(&cards[0], &cards[N]);
    scanf("%d", &M);
    target = (int*) malloc(sizeof(int)*M);
    for (int i=0; i<M; i++) scanf("%d", &target[i]);
    for (int i=0; i<M; i++) printf("%d ", upper(target[i])-lower(target[i])-1);
    return 0;
}