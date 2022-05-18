/*
    N이 주어질 때, 길이가 N이면서 0부터 9까지 숫자가 모두 등장하는 계단 수
    % 1,000,000,000
*/
#include <cstdio>
#define DIV 1000000000
int N, dp[100][10][1<<10];
//          [i][j][k]
//          index i == j(0~9), k: 비트로 0~9 방문여부 표현
int sol() {
    int ans = 0;
    for (int i=N-2; 0<=i; i--) {
        for (int j=0; j<10; j++) {
            for (int k=1; k<(1<<10); k++) {
                switch(j) {
                    case 0:
                        dp[i][j][k|1] = (dp[i][j][k|1] + dp[i+1][1][k]) % DIV;
                        break;
                    case 9:
                        dp[i][j][k|(1<<9)] = (dp[i][j][k|(1<<9)] + dp[i+1][8][k]) % DIV;
                        break;
                    default:
                        dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i+1][j+1][k]) % DIV;
                        dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i+1][j-1][k]) % DIV;
                }
            }
        }
    }
    for (int i=1; i<10; i++) ans = (ans + dp[0][i][(1<<10)-1]) % DIV;
    return ans;
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<10; i++) dp[N-1][i][1<<i] = 1;
    printf("%d\n", sol());
    return 0;
}