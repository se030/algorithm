#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, k, val, dp[10005] = {0, };
    vector<int> coin;

    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        if (val <= k) coin.push_back(val);
    }
    dp[0] = 1;
    for (int i = 0; i < coin.size(); i++) {
        for (int j = coin[i]; j <= k; j++)
            dp[j] = dp[j] + dp[j-coin[i]]; // j원을 만드는 방법 = (j-coin[i])원에 coin[i]짜리 하나를 더하기
    }
    printf("%d\n", dp[k]);
    return 0;
}