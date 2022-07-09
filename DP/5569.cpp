#include <cstdio>
#define MOD 100000
int w, h, dp[101][101][4] = { 0, };
/*
    dp[x][y][0]     x-1, y  방향 변경 가능
    dp[x][y][1]     x-1, y  방향 변경 불가능
    dp[x][y][2]     x, y-1  방향 변경 가능
    dp[x][y][3]     x, y-1  방향 변경 불가능
*/
int sol() {
    for (int i=1; i<=w; i++) dp[i][1][0] = 1;
    for (int j=1; j<=h; j++) dp[1][j][2] = 1;
    for (int i=2; i<=w; i++) {
        for (int j=2; j<=h; j++) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            dp[i][j][1] = dp[i-1][j][2];
            dp[i][j][2] = (dp[i][j-1][2] + dp[i][j-1][3]) % MOD;
            dp[i][j][3] = dp[i][j-1][0];
        }
    }
    return (dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]) % MOD;
}
int main() {
    scanf("%d %d", &w, &h);
    printf("%d\n", sol());
    return 0;
}