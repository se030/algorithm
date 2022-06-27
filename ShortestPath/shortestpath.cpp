#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 2000000000
#define TUP tuple<int, int, int, int>
using namespace std;

int T, N, M, R, K, map[101][101], dx, dy, mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};
char input[5];
int dist(int x, int y) { return abs(dx-x) + abs(dy-y); }

/*
    R, K에서 시작해 mask 111 만들어질 때까지 탐색
        111이 된 지점에서 path + S까지의 거리 중 최소값
        종착지가 A, B, C인 경우 전부 고려해야 함
    queue memory 관리 -> path[101][101][8]: (x,y)에서 mask가 k일 때 최단거리, 더 큰 값은 Q에 넣지않음
*/
void sol(int t) {
    int p, x, y, mask, nx, ny, nmask, tmask, ans = INF;
    vector<vector<vector<int>>> path(101, vector<vector<int>>(101, vector<int>(8, INF)));
    priority_queue<TUP, vector<TUP>, greater<TUP>> Q;
    TUP cur;
    path[R][K][0] = 0;
    Q.push(make_tuple(0, R, K, 0));     // path distance, row, col, mask
    while (Q.size()) {
        cur = Q.top();
        Q.pop();
        p = get<0>(cur), x = get<1>(cur), y = get<2>(cur), mask = get<3>(cur);
        for (int i=0; i<4; i++) {
            nx = x + mx[i];
            ny = y + my[i];
            nmask = mask;
            if (0 < nx && nx <= N && 0 < ny && ny <= M && map[nx][ny] != -1) {
                nmask |= map[nx][ny];
                if (nmask == 7) {
                    tmask |= map[nx][ny];
                    ans = min(ans, p+1+dist(nx, ny));
                    if (tmask == 7) {
                        printf("#%d %d\n", t, ans);
                        return;
                    }
                } else if (p + 1 < path[nx][ny][nmask]) {
                    path[nx][ny][nmask] = p + 1;
                    Q.push(make_tuple(p+1, nx, ny, nmask));
                }
            }
        }
    }
    printf("#%d %d\n", t, ans);
    return;
}
int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &N, &M, &R, &K);
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                scanf("%1s", input);
                if (!strncmp(input, ".", 1)) map[i][j] = 0;
                else if (!strncmp(input, "X", 1)) map[i][j] = -1;   // 지나갈 수 없는 곳
                else if (!strncmp(input, "A", 1)) map[i][j] = 1;    // 001
                else if (!strncmp(input, "B", 1)) map[i][j] = 2;    // 010
                else if (!strncmp(input, "C", 1)) map[i][j] = 4;    // 100
                else if (!strncmp(input, "S", 1)) {
                    map[i][j] = 0;
                    dx = i, dy = j;
                }
            }
        }
        sol(t);
    }
    return 0;
}
