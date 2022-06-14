#include <cstdio>
#include <vector>
using namespace std;
int N, M, invest[301][21], profit, inv,
    dp[21][301],        // i번째 기업까지의 스코프에서 j만큼 투자해 얻는 최대 이익
    path[21][301];      // dp[i][j]기 최대일 때 기업 i에 투자한 금액
vector<int> res;

int main() {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) for (int j=0; j<=M; j++) scanf("%d", &invest[i][j]);

    for (int j=1; j<=M; j++) {
        for (int i=1; i<=N; i++) {
            for (int k=0; k<=i; k++) {
                profit = dp[j-1][i-k] + invest[k][j];
                if (dp[j][i] < profit) {
                    dp[j][i] = profit;
                    path[j][i] = k;
                }
            }
        }
    }

    printf("%d\n", dp[M][N]);
    for (int i=M; 0<i; i--) {
        inv = path[i][N];
        res.push_back(inv);
        N -= inv;
    }
    for (int i=M-1; 0<=i; i--) printf("%d ", res[i]);
    printf("\n");
    return 0;
}