#include <cstdio>
int N, M, uses[101], cost[101];
long long dp[101][10001];
int sol() {
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=100*N; j++) {
            dp[i][j] = dp[i-1][j];
            if (0 <= j-cost[i]) {
                if (dp[i][j] < dp[i-1][j-cost[i]] + uses[i])
                    dp[i][j] = dp[i-1][j-cost[i]] + uses[i];
            }
        }
    }
    for (int i=0; i<=10000; i++)
        if (M <= dp[N][i]) return i;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%d", &uses[i]);
    for (int i=1; i<=N; i++) scanf("%d", &cost[i]);
    printf("%d\n", sol());
    return 0;
}