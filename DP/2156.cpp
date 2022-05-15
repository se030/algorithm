// DP[N] = Max(DP[N - 3] + Arr[N - 1] + Arr[N] , DP[N - 2] + Arr[N] , DP[N - 1])

#include <cstdio>
#include <algorithm>
using namespace std;
int n, wine[10000], dp[10000];
void sol() {
    dp[0] = wine[0];
    dp[1] = dp[0]+wine[1];
    dp[2] = max(wine[0]+wine[2], max(wine[1]+wine[2], dp[1]));
    for (int i=3; i<n; i++)
        dp[i] = max(dp[i-3]+wine[i-1]+wine[i], max(dp[i-2]+wine[i], dp[i-1]));
    printf("%d\n", dp[n-1]);
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &wine[i]);
    sol();
    return 0;
}