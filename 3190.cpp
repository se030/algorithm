#include <cstdio>
#include <map>
using namespace std;

int N, K, L, board[101][101],
    mx[] = {0, 0, 1, 0, -1},
    my[] = {0, 1, 0, -1, 0};
map<int, int> snake;

void sol() {
    int clock = 0, x = 1, y = 1, d = 1, nd, td;

    board[x][y] = d;
    pair<int, int> tail = pair<int,int>(x, y);

    while (true) {
        clock++;
        x += mx[d];
        y += my[d];

        if (x == 0 || x == N + 1 || y == 0 || y == N + 1 || 0 < board[x][y]) {
            printf("%d\n", clock);
            return;
        }

        nd = d;
        if (snake.find(clock) != snake.end()) {
            nd += snake[clock];
            if (nd < 1) nd = 4;
            if (4 < nd) nd = 1;
        }

        if (board[x][y] == -1) {
            board[x][y] = nd;
        } else {
            td = board[tail.first][tail.second];
            board[tail.first][tail.second] = 0;
            tail = pair<int, int>(tail.first + mx[td], tail.second + my[td]);
            
            board[x][y] = nd;
        }

        d = nd;
    }
}

int main() {
    int x, y;
    char dir;

    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &x, &y);
        board[x][y] = -1;
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &x, &dir);
        snake.insert(pair<int, int>(x, dir == 'L' ? -1 : 1));
    }

    sol();
    return 0;
}