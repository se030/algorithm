#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N, *A, M, num;
int search(int a) {
    int lo = 0, hi = N;
    while (lo + 1 <= hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] == a) return 1;
        else if (A[mid] < a) lo = mid+1;
        else hi = mid;
    }
    return 0;
}
int main() {
    scanf("%d", &N);
    A = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sort(&A[0], &A[N]);
    scanf("%d", &M);
    for (int i = 0; i<M; i++) {
        scanf("%d", &num);
        printf("%d\n", search(num));
    }
    return 0;
}