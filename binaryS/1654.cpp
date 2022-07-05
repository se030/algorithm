#include <cstdio>
#include <cstdlib>

int main() {
    int K, N;
    long long *lan, lo = 0, hi = 0;
    scanf("%d %d", &K, &N);
    lan = (long long*)malloc(sizeof(long long)*K);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &lan[i]);
        if (hi < lan[i]) hi = lan[i] + 1;
    }

    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        int n = 0;
        for (int i = 0; i < K; i++) n += lan[i] / mid;

        printf("%lld to %lld (%lld), %d lans\n", lo, hi, mid, n);
        if (N <= n) lo = mid;
        else hi = mid;
    }
    printf("%lld", lo);

    return 0;
}