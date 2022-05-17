#include <cstdio>
int N, M, map[501][501],
    dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1},
    dp[501][501]; // # of paths from (x,y) to (N-1, M-1)
int dfs(int x, int y) {
    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[ny][nx] < map[y][x])
                    dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}
int main() {
    scanf("%d %d", &M, &N);
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            dp[j][i] = -1;
        }
    }
    dp[N-1][M-1] = 1;
    printf("%d\n", dfs(0, 0));
    return 0;
}