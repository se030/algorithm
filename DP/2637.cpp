#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, X, Y, K, in[101] = {0, }, cnt[101], cur;
vector<pair<int,int>> parts[101];

void sol() {
    vector<int> ans;
    queue<int> Q;
    Q.push(N);
    cnt[N] = 1;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        if (parts[cur].empty()) ans.push_back(cur);
        for (int i=0; i<parts[cur].size(); i++) {
            Y = parts[cur][i].first;
            K = parts[cur][i].second;
            cnt[Y] += K * cnt[cur];
            if (!--in[Y]) Q.push(Y);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) printf("%d %d\n", ans[i], cnt[ans[i]]);
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &X, &Y, &K);
        parts[X].push_back({Y, K});
        in[Y]++;
    }
    sol();
    return 0;
}