// 시작점을 알지 못하고, 존재하는 사이클을 찾는 문제

#include <cstdio>
#define INF 2000000000
using namespace std;
int V, E, a, b, c, edge[401][401], dist[401][401];

void floyd() {
    for (int j=1; j<=V; j++) {
        for (int i=1; i<=V; i++) {
            if (dist[i][j] == INF) continue;
            for (int k=1; k<=V; k++) {
                if (dist[j][k] == INF) continue;
                if (dist[i][j] + dist[j][k] < dist[i][k])
                    dist[i][k] = dist[i][j] + dist[j][k];
            }
        }
    }
}

void sol() {
    int ans = INF;
    floyd();
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            if (edge[j][i]) {
                if (dist[i][j] + edge[j][i] < ans)
                    ans = dist[i][j] + edge[j][i];
            }
        }
    }
    printf("%d\n", ans == INF? -1:ans);
}

int main() {
    scanf("%d %d", &V, &E);
    for (int i=1; i<=V; i++) {
        for (int j=1; j<=V; j++) {
            edge[i][j] = 0;
            dist[i][j] = INF;
        }
    }
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge[a][b] = c;
        dist[a][b] = c;
    }
    sol();
    return 0;
}