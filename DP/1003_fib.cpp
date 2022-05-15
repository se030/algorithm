#include <cstdio>
int T, N, dp[41] = {0, };
int fibonacci(int n) {
    if (n && !dp[n])
        dp[n] = fibonacci(n-2) + fibonacci(n-1);
    return dp[n];
}
int main() {
    dp[0] = 0;
    dp[1] = 1;
    fibonacci(40);
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        scanf("%d", &N);
        printf("%d %d\n", N? dp[N-1]:1, dp[N]);
    }
    return 0;
}