#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N, a, b, dp[100];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> input;
vector<pair<int, int>> findLis;
void sol() {
    while (input.size()) {
        findLis.push_back(input.top());
        input.pop();
    }

    // dp[k]에는 k까지의 최장증가수열 길이가 저장되어있음
    //  각각의 i에 대해 내 앞의 애들을 다 확인 + 내 앞에 나보다 작은 애의 dp값을 확인해서 maxv 갱신
    int maxv, ret = 1;
    for (int i=0; i<N; i++) {
        maxv = 0;       // for lis length ~i
        for (int j=0; j<i; j++)
            if (findLis[i].second > findLis[j].second) maxv = max(maxv, dp[j]);
        dp[i] = maxv + 1;
        ret = max(ret, dp[i]);
    }
    printf("%d\n", N-ret);
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &a, &b);
        input.push({a, b});
    }
    sol();
    return 0;
}