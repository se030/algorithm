/* 
    two bits representing -> touched 0 / 9
        00 none
        01 touched 0
        10 touched 9
        11 condition met
*/
#include <cstdio>
#define DIV 1000000000
int N, dp[100][10][4];
int sol() {
    int ans = 0;
    for (int i=N-2; 0<=i; i--) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<4; k++) {
                if (0 <= j-1)
                    dp[i][j-1][k|(j-1==0)] = (dp[i][j-1][k|(j-1==0)] + dp[i+1][j][k]) % DIV;
                if (j+1 <= 9)
                    dp[i][j+1][k|2*(j+1==9)] = (dp[i][j+1][k|2*(j+1==9)] + dp[i+1][j][k]) % DIV;
            }
        }
    }
    for (int i=1; i<10; i++) ans = (ans + dp[0][i][3]) % DIV;
    return ans;
}
int main() {
    scanf("%d", &N);
    for (int i=1; i<9; i++) dp[N-1][i][0] = 1;
    dp[N-1][0][1] = 1;
    dp[N-1][9][2] = 1;
    printf("%d\n", sol());
    return 0;
}