#include <cstdio>
#include <vector>
#include <queue>
#define INF 70000000
using namespace std;
int N, M, A, B, C;
long long int dist[50001];
vector<pair<int, int>> edge[50001];
priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> Q;
void sol() {
    for (int i=1; i<=N; i++)
        dist[i] = INF;
    dist[1] = 0;
    Q.push({dist[1], 1});
    while (Q.size()) {
        pair<long long int, int> cur = Q.top();
        Q.pop();
        for (int i=0; i<edge[cur.second].size(); i++) {
            pair<int, int> e = edge[cur.second][i];
            if (cur.first + e.second < dist[e.first]) {
                dist[e.first] = cur.first + e.second;
                Q.push({dist[e.first], e.first});
            }
        }
    }
    printf("%lld\n", dist[N]);
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    sol();
    return 0;
}