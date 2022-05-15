#include <cstdio>
#include <algorithm>
using namespace std;
int N, A[1000], dp[1000];
void sol() {
    int compv, idx = 0, I = 1, D = 1;
    // LIS
    dp[idx] = 1;
    for (int i=0; i<N; i++) {
        compv = 0;
        for (int j=0; j<i; j++) {
            if (A[i] > A[j]) {
                compv = max(compv, dp[j]);
                printf("[%d] < [%d], compv: %d", j, i, compv);
            }
        }
        dp[i] = compv + 1;
        if (I < dp[i]) {
            I = dp[i];
            idx = i;
            printf("idx became %d\n", idx);
        }
    }
    // LDS
    dp[idx] = 1;
    for (int i=idx; i<N; i++) {
        compv  = 0;
        for (int j=idx; j<i; j++) if (A[j] > A[i]) compv = max(compv, dp[j]);
        dp[i] = compv + 1;
        D = max(D, dp[i]);
    }
    printf("%d\n", I+D-1);
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &A[i]);
    sol();
    return 0;
}