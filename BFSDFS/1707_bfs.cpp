#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define RED 1
#define BLACK 2
int K, V, E, u, v, mark[20001];
vector<int> connected[20001];
bool sol() {
    queue<int> Q;
    int adj;
    for (int vtx=1; vtx<=V; vtx++) {
        if (!mark[vtx]) {
            Q.push(vtx);
            mark[vtx] = RED;
            while (Q.size()) {
                int cur = Q.front();
                Q.pop();
                for (int i=0; i<connected[cur].size(); i++) {
                    adj = connected[cur][i];
                    if (!mark[adj]) {
                        Q.push(adj);
                        mark[adj] = mark[cur]==RED? BLACK:RED;
                    }
                }
            }
        }
    }
    for (int i=1; i<=V; i++) {
        for (int j=0; j<connected[i].size(); j++) {
            adj = connected[i][j];
            if (mark[i] == mark[adj]) return false;
        }
    }
    return true;
}
int main() {
    scanf("%d", &K);
    for (int t=0; t<K; t++) {
        scanf("%d %d", &V, &E);
        memset(mark, 0, sizeof(int)*(V+1));
        for (int i=1; i<=V; i++) connected[i].clear();
        for (int e=0; e<E; e++) {
            scanf("%d %d", &u, &v);
            connected[u].push_back(v);
            connected[v].push_back(u);
        }
        printf("%s\n", sol()? "YES":"NO");
    }
    return 0;
}

/*
    bfs 또는 dfs로 탐색하면서 인접 노드를 다른 색으로 칠함

        1번 정점에서만 탐색을 해서는 안 됩니다. 1번 정점과 연결되지 않은 다른 정점들 사이에서 이분 그래프를 못 만들 수 있습니다.
        1번 뿐만 아니라, 어느 정점이라도 마찬가지입니다. 주어지는 그래프는 연결 그래프가 아닐 수 있습니다.
        
        간선 정보 순서대로, 또는 임의의 순서로 정렬해놓고 하나씩 보면서 집합을 임의로 정해주는 것도 안 됩니다.
        지금 당장 집합을 정한 것 때문에 나중에 이분 그래프를 못 만들게 될 수도 있습니다. 그래프 정보가 완전히 들어오기 전까지는 섣부른 판단은 금물입니다.
*/