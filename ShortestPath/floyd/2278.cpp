#include <cstdio>
#include <vector>
#define INF 1000000
using namespace std;
int N, M, dist[101][101] = { 0, }, cnt;
vector<pair<int, int>> edges[101];
bool isValid() {
    for (int a = 1; a <= N; a++) {
        for (int b = a+1; b <= N; b++) {
            if (dist[a][b] != INF) {
                if (500 < dist[a][b]) return false;
                edges[a].push_back({b, dist[a][b]});
            }
        }
    }
    return true;
}
bool sol() {
    cnt = (N * (N-1)) / 2;
    if (cnt == M) return isValid();
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (i == k) continue;
            for (int j = 1; j <= N; j++) {
                if (i == j || j == k) continue;
                if (dist[i][k] + dist[k][j] == dist[i][j]) {
                    dist[i][j] = INF;   
                    dist[j][i] = INF;
                    cnt--;
                    if (cnt == M) return isValid();
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            scanf("%d", &dist[i][j]);
            dist[j][i] = dist[i][j];
        }
    }
    if (sol()) {
        printf("1\n");
        for (int i=0; i<=N; i++)
            for (auto e: edges[i]) printf("%d %d %d\n", i, e.first, e.second);
    }
    else printf("0\n");
    return 0;
}