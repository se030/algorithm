// s에서 출발, 가능한 도착지를 구해야 함
// 최단경로 중 g-h를 지나는 것

#include <cstdio>
#include <vector>
#include <queue>
#define INF 2147483647 / 2 * 2
using namespace std;
int T, n, m, t, s, g, h, a, b, d, x, dist[2001];
vector<pair<int, int>> edge[2001];
vector<int> dest;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
priority_queue<int, vector<int>, greater<int>> ans;
void dijk() {
    for (int i=1; i<=n; i++)
        dist[i] = INF;
    dist[s] = 0;
    Q.push({dist[s], s});
    while (Q.size()) {
        pair<int, int> cur = Q.top();
        Q.pop();
        for (int i=0; i<edge[cur.second].size(); i++) {
            pair<int, int> E = edge[cur.second][i];
            if (cur.first + E.second < dist[E.first]) {
                dist[E.first] = cur.first + E.second;
                Q.push({dist[E.first], E.first});
            }
        }
    }
}
void sol() {
    dijk();
    for (int i=0; i<dest.size(); i++)
        if (dist[dest[i]] % 2) ans.push(dest[i]);
    while (ans.size()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    printf("\n");
}
int main() {
    scanf("%d", &T);
    for (int test=0; test<T; test++) {
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        for (int iter=0; iter<m; iter++) {
            scanf("%d %d %d", &a, &b, &d);
            if ((a == g && b == h) || (a == h && b == g)) {
                // 나머지 간선들의 weight는 짝수, g-h는 홀수로 설정해서 dist 결과값이 홀수이면 g-h를 지난 것을 알 수 있음
                edge[a].push_back({b, 2*d - 1});
                edge[b].push_back({a, 2*d - 1});
            } else {
                edge[a].push_back({b, 2*d});
                edge[b].push_back({a, 2*d});
            }
        }
        for (int iter=0; iter<t; iter++) {
            scanf("%d", &x);
            dest.push_back(x);
        }
        sol();
        for (int iter=1; iter<=n; iter++) edge[iter].clear();
        dest.clear();
    }
    return 0;
}