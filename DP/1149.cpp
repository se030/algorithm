// 지금 turn에서 최선의 선택이 결과적으로 최선이 아닐 수 있음
//  backtracking으로 접근할 것

#include <cstdio>
#include <algorithm>
using namespace std;
int N, dp[3], cost[3];
int main() {
    scanf("%d", &N);
    scanf("%d %d %d", &dp[0], &dp[1], &dp[2]);
    for (int i=1; i<N; i++) {
        scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);
        cost[0] = cost[0] + min(dp[1], dp[2]);
        cost[1] = cost[1] + min(dp[0], dp[2]);
        cost[2] = cost[2] + min(dp[0], dp[1]);
        dp[0] = cost[0];
        dp[1] = cost[1];
        dp[2] = cost[2];
    }
    printf("%d\n", min(dp[0], min(dp[1], dp[2])));
    return 0;
}