#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int N, M, a, b, depth[100001], max_depth, parent[100001][18];
vector<int> edge[100001];
void dfs(int cur, int d, int p) {
    depth[cur] = d;
    parent[cur][0] = p;
    for (int i = 1; i <= max_depth; i++) 
        parent[cur][i] = parent[parent[cur][i-1]][i-1];    
    for (auto next: edge[cur])
        if (depth[next] == -1) dfs(next, d+1, cur);
}
int lca(int a, int b) {
    if (a == 1 || b == 1) return 1;
    int x = depth[a] < depth[b]? a : b, y = depth[a] < depth[b]? b : a;
    // to same depth
    int p, diff = depth[y] - depth[x];
    for (p = 0; 0 < diff; p++, diff >>= 1) if (diff & 1) y = parent[y][p];
    while (x != y) {
        for (p = 0; p <= depth[a]; p++)
            if (parent[x][p] == parent[y][p]) break;
        if (p != 0) p--;
        x = parent[x][p], y = parent[y][p];
    }
    return x;
}
int main() {
    scanf("%d", &N);
    memset(depth, -1, sizeof(int)*(N+1));
    max_depth = floor(log2(N));
    for (int i=0; i<N-1; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0, 1);
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}