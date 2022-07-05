#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#define WITHIN_AT 0 <= nx && nx < N && 0 <= ny && ny < M
using namespace std;
int N, M, iceberg[300][300][2], topVal, cnt, nx, ny, visited[300][300],
    mx[] = {-1, 1, 0, 0}, my[] = {0, 0, -1, 1};
pair<int, int> top;

int dfs(int x, int y, int idx) {
    int ans = 1;
    visited[x][y] = 1;
    for (int m=0; m<4; m++) {
        nx = x + mx[m];
        ny = y + my[m];
        if (WITHIN_AT && iceberg[nx][ny][idx] && !visited[nx][ny])
            ans += dfs(nx, ny, idx);
    }
    return ans;
}
int sol() {
    for (int idx=1; ; idx++) {
        topVal = 0, cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                iceberg[i][j][idx % 2] = iceberg[i][j][(idx-1) % 2];
                for (int m=0; m<4; m++) {
                    nx = i + mx[m];
                    ny = j + my[m];
                    if (WITHIN_AT && !iceberg[nx][ny][(idx-1) % 2])
                        iceberg[i][j][idx % 2] = max(iceberg[i][j][idx % 2] - 1, 0);
                }
                if (topVal < iceberg[i][j][idx % 2]) {
                    topVal = iceberg[i][j][idx % 2];
                    top = {i, j};
                }
                if (iceberg[i][j][idx % 2]) cnt++;
            }
        }
        if (!cnt) return 0;
        memset(visited, 0, sizeof(int)*300*300);
        if (dfs(top.first, top.second, idx % 2) != cnt) return idx;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) scanf("%d", &iceberg[i][j][0]);
    printf("%d\n", sol());
    return 0;
}