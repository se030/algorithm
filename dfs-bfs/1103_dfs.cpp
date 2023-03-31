// 최대

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 1000000000
using namespace std;
int N, M, board[50][50], dp[50][50],                                        // reachable_max from (x, y)
    mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1},
    nx, ny, temp;
char input[2];
bool visited[50][50];

int dfs(int x, int y) {
    if (visited[x][y]) return INF;
    if (dp[x][y] == -1) {
        dp[x][y] = 1;                                                       // 방문하면서 depth 1로 만들어주고
        visited[x][y] = true;
        for (int i=0; i<4; i++) {                                           // 네 방향 중 갈 수 있는 경로 dfs
            nx = x + board[x][y] * mx[i];
            ny = y + board[x][y] * my[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny])    // 인덱스 체크
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
        visited[x][y] = false;
    }
    return dp[x][y];
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            visited[i][j] = false;
            dp[i][j] = -1;
            scanf("%1s", input);
            if (strncmp(input, "H", 1)) board[i][j] = atoi(input);
            else board[i][j] = 0;
        }
    }
    temp = dfs(0, 0);
    printf("%d\n", INF < temp? -1 : temp);
    return 0;
}