/*
    왼쪽에서 시작한 Increasing sequence = L
    오른쪽에서 시작한 Increasing sequence = R
    이 되는 빌딩 배치 경우의 수
*/
#include <cstdio>
#define M 1000000007
int N, L, R;
long long int dp[101][101][101];
void sol() {
    dp[1][1][1] =1;
    for (int n = 2; n <= N; n++) {
        for (int l=1; l <= N; l++) {
            for (int r=1; r <= N; r++) {
                dp[n][l][r] = (
                    dp[n-1][l-1][r]         // 왼쪽 끝
                    + dp[n-1][l][r-1]       // 오른쪽 끝
                    + dp[n-1][l][r]*(n-2)   // 중간
                ) % M;
            }
        }
    }
    printf("%lld\n", dp[N][L][R]);
}
int main() {
    scanf("%d %d %d", &N, &L, &R);
    sol();
    return 0;
}