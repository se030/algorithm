#include <cstdio>
#include <utility>
#include <cmath>
#define X first
#define Y second
using namespace std;
int N, T, M, s, x, y, A, B, teleport[1001], dist[1001][1001] = { 0, };
pair<int, int> city[1001];
void sol() {
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            dist[i][j] = abs(city[i].X - city[j].X) + abs(city[i].Y - city[j].Y);
            if (teleport[i] && teleport[j] && T < dist[i][j])
                dist[i][j] = T;
            dist[j][i] = dist[i][j];
        }
    }
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            if (i == k) continue;
            for (int j=1; j<=N; j++) {
                if (i == j || j == k) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &T);
    for (int i=1; i<=N; i++) {
        scanf("%d %d %d", &s, &x, &y);
        teleport[i] = s;
        city[i] = { x, y };
    }
    sol();
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", dist[A][B]);
    }
    return 0;
}