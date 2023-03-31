/*
    topological sort
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[32001];
int N, M, p, c, indegree[32001];
void sol() {
    queue<int> q;
    int cur;
    for (int i=1; i<=N; i++) if (indegree[i] == 0) q.push(i);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        printf("%d ", cur);

        for (int i=0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++){
        scanf("%d %d", &p, &c);
        graph[p].push_back(c);
        indegree[c]++;
    }
    sol();
    return 0;
}