/*
    topological sort
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, pre, buildTime[501], in[501] = { 0, }, ans[501] = { 0, };
vector<int> enables[501];
void sol() {
    queue<int> update;
    int cur;
    for (int i=1; i<=N; i++) if (!in[i]) update.push(i);
    while (!update.empty()) {
        cur = update.front();
        update.pop();
        for (auto next: enables[cur]) {
            in[next]--;
            if (!in[next]) update.push(next);
            ans[next] = max(ans[cur] + buildTime[next], ans[next]);
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &buildTime[i]);
        ans[i] = buildTime[i];
        while (true) {
            scanf("%d", &pre);
            if (pre == -1) break;
            enables[pre].push_back(i);
            in[i]++;
        }
    }
    sol();
    for (int i=1; i<=N; i++) printf("%d\n", ans[i]);
    return 0;
}