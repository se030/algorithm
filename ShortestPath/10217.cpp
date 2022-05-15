#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;
int T, N, M, K, u, v, c, d,
    // M원 이하, 가장 빠른 길 -> 구하면서 비용이 M 이상이 되면 INF로 업데이트하기
        // dist는 더 길지만 cost가 적어 결과적으로는 갈 수 있는 경로를 놓침 < short dist, over cost를 선택
    // Sol. 모든 가능한 cost에 대해 최소 거리를 봐야 !!!!
    dist[101][10001], // i까지 j의 비용으로 가는 최소시간
    visited[101];
typedef struct ticket {
    int dest;
    int c;
    int d;
} ticket;
vector<ticket*> tickets[101];
priority_queue<tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>> Q;

void sol() {
    for (int i=1; i<=N; i++) {
        visited[i] = 0;
        for (int j=1; j<=M; j++)
            dist[i][j] = INF;
    }
    dist[1][0] = 0;
    visited[1] = 1;
    Q.push(make_tuple(dist[1][0], 1, 0)); // minTime, dest, cost
    while (Q.size()) {
        tuple<int, int, int> cur = Q.top();
        Q.pop();
        int start = get<1>(cur);
        for (int i=0; i<tickets[start].size(); i++) {
            ticket tkt = *tickets[start][i];
            int t_dest = tkt.dest;
            int D_cost = get<2>(cur) + tkt.c;
            int D_time = get<0>(cur) + tkt.d;
            if (D_cost > M) continue;
            if (!visited[t_dest] || D_time < dist[t_dest][D_cost]) {
                dist[t_dest][D_cost] = D_time;
                Q.push(make_tuple(D_time, t_dest, D_cost));
                visited[t_dest] = 1;
            }
        }
    }
    int ans = INF;
    for (int i = 1; i<=M; i++) {
        if (dist[N][i] != INF)
            ans = min(ans, dist[N][i]);
    }
    if (ans == INF) printf("%s\n", "Poor KCM");
    else printf("%d\n", ans);
}

int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        scanf("%d %d %d", &N, &M, &K);
        for (int k=0; k<K; k++) {
            scanf("%d %d %d %d", &u, &v, &c, &d);
            ticket* tkt_new = (ticket*)malloc(sizeof(ticket));
            tkt_new->dest = v;
            tkt_new->c = c;
            tkt_new->d = d;
            tickets[u].push_back(tkt_new);
        }
        sol();
        for (int i=1; i<=N; i++)
            tickets[i].clear();
    }
    return 0;
}