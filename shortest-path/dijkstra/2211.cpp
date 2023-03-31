#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define PAIR pair<int, int>
#define INF 30000
using namespace std;
int N, M, A, B, C, cost[1001], lan[1001];
vector<PAIR> net[1001], ans;
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> Q;

void sol() {
    PAIR cur;
    cost[1] = 0;
    Q.push({cost[1], 1});
    while (!Q.empty()) {
        cur = Q.top();
        Q.pop();
        for (auto next: net[cur.second]) {
            if (cur.first + next.second < cost[next.first]) {
                cost[next.first] = cur.first + next.second;
                lan[next.first] = cur.second;
                Q.push({cost[next.first], next.first});
            }
        }
    }
    for (int i=1; i<=N; i++)
        if (lan[i]) ans.push_back({i, lan[i]});
}
int main() {
    scanf("%d %d", &N, &M);
    memset(cost, INF, sizeof(int)*(N+1));
    memset(lan, 0, sizeof(int)*(N+1));
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        net[A].push_back({B, C});
        net[B].push_back({A, C});
    }
    sol();
    printf("%d\n", int(ans.size()));
    for (auto p: ans) printf("%d %d\n", p.first, p.second);
    return 0;
}