#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int N, T, K[101], S[101], dp[101][10001];   // 단원 N까지 T의 시간으로 얻을 수 있는 점수
    scanf("%d %d", &N, &T);
    for (int i=1; i<=N; i++) scanf("%d %d", &K[i], &S[i]);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=T; j++) {
            if (j < K[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-K[i]]+S[i]);
        }
    }
    printf("%d\n", dp[N][T]);
    return 0;
}