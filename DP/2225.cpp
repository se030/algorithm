#include <cstdio>

int N, K, dp[201][201]; // 정수 i개까지의 합이 j인 경우의 수

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N; i++ ) {
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                dp[k][i] += dp[k - 1][i - j];
                dp[k][i] %= 1000000000;
            }
        }
    }

    printf("%d\n", dp[K][N]);

    return 0;
}