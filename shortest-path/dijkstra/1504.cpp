/*
    1-v1-v2-N
    1-v2-v1-N
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 500000000
using namespace std;

int N, E, a, b, c, v1, v2;
long long int dist[801], v1first = 0, v2first = 0;
vector<pair<int, int>> edge[801];   // edge[k]: k에 연결된 엣지 정보 {to, cost}
priority_queue<pair<long long int, int>,
    vector<pair<long long int, int>>,
    greater<pair<long long int, int>>> Q;
void init(int n){
    for (int i=1; i<801; i++)
        dist[i] = INF;
    dist[n] = 0;
    Q.push({dist[n], n});   // Q: 현재 dist set {dist, current}
}
void dijk(int n) {
    init(n);
    while (Q.size()) {
        pair<long long int, int> cur = Q.top();
        Q.pop();
        for (int i=0; i<edge[cur.second].size(); i++) {
            pair<int, int> e = edge[cur.second][i]; // to, cost
            if (cur.first + e.second < dist[e.first]) {
                dist[e.first] = cur.first + e.second;
                Q.push({dist[e.first], e.first});
            }
        }
    }
}
void sol() {
    dijk(1);
    v1first += dist[v1];
    v2first += dist[v2];
    dijk(v1);
    v1first += dist[v2];
    v2first += dist[v2];
    dijk(N);
    v1first += dist[v2];
    v2first += dist[v1];
    long long int res = min(v1first, v2first);
    printf("%lld\n", INF <= res? -1:res);
}
int main() {
    scanf("%d %d", &N, &E);
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    scanf("%d %d", &v1, &v2);
    sol();
    return 0;
}