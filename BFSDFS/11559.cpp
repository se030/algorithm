// 뿌요뿌요..
#include <cstdio>
#include <cstring>
#define ITERATE_PUYOS for (int i=0; i<12; i++) { for (int j=0; j<6; j++) {
#define WITHIN_FIELD 0 <= nx && nx < 12 && 0 <= ny && ny < 6
using namespace std;
int puyo[12][6], newPuyo[12][6],
    nx, ny, moveY, ans = 0,
    mx[] = { 0, 0, 1, -1 },
    my[] = { -1, 1, 0, 0 };
bool puyoChain = true, visited[12][6], popped[12][6];
char chr[5];

int dfs(int x, int y) {
    int samePuyo = 1;
    visited[x][y] = 1;
    for (int i=0; i<4; i++) {
        nx = x + mx[i];
        ny = y + my[i];
        if (WITHIN_FIELD && !visited[nx][ny]) if (puyo[x][y] == puyo[nx][ny]) samePuyo += dfs(nx, ny);
    }
    return samePuyo;
}
void popPuyo(int x, int y) {
    popped[x][y] = 1;
    for (int i=0; i<4; i++) {
        nx = x + mx[i];
        ny = y + my[i];
        if (WITHIN_FIELD && !popped[nx][ny]) if (puyo[x][y] == puyo[nx][ny]) popPuyo(nx, ny);
    }
}
void movePuyo() {
    for (int j=0; j<6; j++) {
        moveY = 0;
        for (int i=11; 0<=i; i--) {
            if (popped[i][j]) moveY++;
            else newPuyo[i+moveY][j] = puyo[i][j];
        }
    }
    memcpy(puyo, newPuyo, sizeof(int)*6*12);
}
int sol() {
    puyoChain = false;
    ITERATE_PUYOS
        visited[i][j] = false;
        popped[i][j] = false;
        newPuyo[i][j] = 0;
    }}
    ITERATE_PUYOS
        if (puyo[i][j] && !visited[i][j]) {
            if (4 <= dfs(i, j)) {
                puyoChain = true;
                popPuyo(i, j);
            }
        }
    }}
    movePuyo();
    return puyoChain? 1 : 0;
}
int main() {
    ITERATE_PUYOS
        scanf("%1s", chr);
        if (!strncmp(chr, ".", 1)) puyo[i][j] = 0;
        else if (!strncmp(chr, ".", 1)) puyo[i][j] = 0;
        else if (!strncmp(chr, "R", 1)) puyo[i][j] = 1;
        else if (!strncmp(chr, "G", 1)) puyo[i][j] = 2;
        else if (!strncmp(chr, "B", 1)) puyo[i][j] = 3;
        else if (!strncmp(chr, "P", 1)) puyo[i][j] = 4;
        else if (!strncmp(chr, "Y", 1)) puyo[i][j] = 5;
    }}
    while (puyoChain) ans += sol();
    printf("%d\n", ans);
    return 0;
}