#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int M, N, H, cnt = 0, ripe = 0, box[100][100][100],
    mx[] = {0, 0, 1, -1, 0, 0},
    my[] = {0, 0, 0, 0, 1, -1},
    mz[] = {1, -1, 0, 0, 0, 0},
    nx, ny, nz, ans = -1;
queue<tuple<int, int, int, int>> Q;
int main(){
    scanf("%d %d %d", &M, &N, &H);
    for (int h=0; h<H; h++) {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                scanf("%d", &box[h][n][m]);
                if (box[h][n][m] != -1) cnt++;
                if (box[h][n][m] == 1) {
                    Q.push(make_tuple(h, n, m, 0));
                    ripe++;
                }
            }
        }
    }
    while (Q.size()) {
        if (ripe == cnt) {
            ans = get<3>(Q.back());
            break;
        }
        tuple<int, int, int, int> cur = Q.front();
        Q.pop();
        for (int m=0; m<6; m++) {
            nz = get<0>(cur) + mz[m];
            ny = get<1>(cur) + my[m];
            nx = get<2>(cur) + mx[m];
            if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H && !box[nz][ny][nx]) {
                box[nz][ny][nx] = 1;
                Q.push(make_tuple(nz, ny, nx, get<3>(cur)+1));
                ripe++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}