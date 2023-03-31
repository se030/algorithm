#include <cstdio>
#include <cstdlib>
#include <queue>
#include <tuple>
using namespace std;
int N, M, x, y, w,
    mx[] = {0, 0, 1, -1}, my[] = {1, -1, 0, 0},
    visited[1001][1001][2];  // 부수고 온 경우와 안부수고 온 경우 다르게 생각
int main() {
    fill(&visited[0][0][0], &visited[1000][1000][2], 0); // 주의: 좌표 (1,1)부터 시작
    scanf("%d %d", &N, &M);
    int** map = (int**)malloc(sizeof(int*)*(N+1));
    for (int i=1; i<=N; i++) {
        map[i] = (int*)malloc(sizeof(int)*(M+1));
        for (int j=1; j<=M; j++) scanf("%1d", &map[i][j]);
    }
    queue<tuple<int, int, int, int>> Q; // x, y, dist, if prev path had 1
    Q.push(make_tuple(1, 1, 1, 0));
    visited[1][1][0] = 1;
    while (Q.size()) {
        tuple<int, int, int, int> cur = Q.front();
        Q.pop();
        x = get<0>(cur);
        y = get<1>(cur);
        if (x == N && y == M) {
            printf("%d\n", get<2>(cur));
            return 0;
        }
        for (int i=0; i<4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            w = get<3>(cur); // 벽을 부시고 왔는지
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && !visited[nx][ny][w]) {
                if (map[nx][ny] == 0) {
                    Q.push(make_tuple(nx, ny, get<2>(cur)+1, w));
                    visited[nx][ny][w] = 1;
                } else if (map[nx][ny] == 1 && w == 0) {
                    Q.push(make_tuple(nx, ny, get<2>(cur)+1, 1));
                    visited[nx][ny][w] = 1;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}