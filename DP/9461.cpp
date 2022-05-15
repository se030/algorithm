#include <cstdio>
int T, N;
long long int dp[101] = {0, };
long long int calc(int n) {
    if (n && !dp[n]) dp[n] = calc(n-2) + calc(n-3);
    return dp[n];
}
int main() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        scanf("%d", &N);
        printf("%lld\n", calc(N));
    }
    return 0;
}