// greedy approach
// 시작점으로부터 연결된 V 중 최소비용으로 갈 수 있는 애부터
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int V, E, K, u, v, w, visited[20001], dist[20001];

vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;

void dijk() {
    visited[K] = 1;
    dist[K] = 0;
    Q.push({dist[K], K});
    while (Q.size()) {
        pair<int, int> cur = Q.top();
        Q.pop();
        if (visited[cur.second] == 1) {
            for (int i=0; i<edge[cur.second].size(); i++) {
                pair<int, int> e = edge[cur.second][i];
                if (e.first != K) {
                    if (dist[e.first] == 0) {
                        visited[e.first] = 1;
                        dist[e.first] = cur.first + e.second;
                        Q.push({dist[e.first], e.first});
                    } else if (cur.first + e.second < dist[e.first]) {
                        dist[e.first] = cur.first + e.second;
                        Q.push({dist[e.first], e.first});
                    }
                }
            }
            visited[cur.second] = 2;
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] || i == K) printf("%d\n", dist[i]);
        else printf("INF\n");
    }
}
int main() {
    scanf("%d %d %d", &V, &E, &K);
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back({v, w});
    }
    dijk();
    return 0;
}