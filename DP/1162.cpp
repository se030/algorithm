#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define TUP tuple<long long int, int, int>
#define LLONG 9000000000000000000
using namespace std;
int N, M, K, from, to, cost, k;
long long int ans = LLONG;
vector<vector<pair<int, int>>> edge(10001, vector<pair<int, int>>());

void sol() {
    long long int time;
    vector<vector<long long int>> C(10001, vector<long long int>(21, LLONG));   // C[10001][21]: 도시 i까지, 도로 k개 포장 최소시간
    priority_queue<TUP, vector<TUP>, greater<TUP>> Q;
    TUP cur;
    Q.push(make_tuple(0, 1, 0));    // time, city, k
    C[1][0] = 0;
    while (!Q.empty()) {
        cur = Q.top();
        Q.pop();
        time = get<0>(cur), from = get<1>(cur), k = get<2>(cur);
        if (C[from][k] < time) continue;    // prevents timeout
        for (int i=0; i<edge[from].size(); i++) {
            to = edge[from][i].first, cost = edge[from][i].second;
            if (C[from][k] + cost < C[to][k]) {
                C[to][k] = C[from][k] + cost;
                Q.push(make_tuple(C[to][k], to, k));
            }
            if (k < K && C[from][k] < C[to][k+1]) {
                C[to][k+1] = C[from][k];
                Q.push(make_tuple(C[to][k+1], to, k+1));
            }
        }
    }
    for (int i=0; i<=K; i++) ans = min(ans, C[N][i]);
    printf("%lld\n", ans);
}
int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        edge[from].push_back({to, cost});
        edge[to].push_back({from, cost});
    }
    sol();
    return 0;
}