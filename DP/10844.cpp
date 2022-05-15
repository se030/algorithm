#include <cstdio>
#define mod 1000000000
int N;
long long int ans = 0, dp[100][10]; // 마지막 자릿수가 b인 a+1자리 계단수
void sol(int n) {
    for (int i=1; i<n; i++) {
        for (int j=0; j<10; j++) {
            if (j == 9) dp[i][9] = dp[i-1][8];
            else if (j == 0) dp[i][0] = dp[i-1][1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }
    for (int i=0; i<10; i++) ans += dp[n-1][i];
    printf("%lld", ans % mod);
}
int main() {
    dp[0][0] = 0;
    for (int i=1; i<10; i++) dp[0][i] = 1;
    scanf("%d", &N);
    sol(N);
    return 0;
}