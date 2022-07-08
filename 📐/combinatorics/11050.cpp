/*
    nCk = n-1Ck-1 + n-1Ck
*/
#include <cstdio>
int N, K;
int comb(int n, int k) {
    if (n == k || k == 0) return 1;
    if (k == 1) return n;
    return comb(n-1, k-1) + comb(n-1, k);
}
int main() {
    scanf("%d %d", &N, &K);
    printf("%d\n", comb(N, K));
    return 0;
}