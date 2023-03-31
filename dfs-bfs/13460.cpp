#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#define X first
#define Y second
#define PAIR pair<int, int>
using namespace std;
enum Board {
    Wall, Path, Hole
};
int N, M, board[10][10], checked[10][10][10][10] = {0, },   // (red.X, red.Y), (blue.X, blue.Y) 확인 여부
    mv, mx[] = { -1, 1, 0, 0 }, my[] = { 0, 0, -1, 1 };
PAIR red, blue, newRed, newBlue;
char input[11];

bool withinBox(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}
int sol() {
    queue<tuple<PAIR, PAIR, int>> Q;
    tuple<PAIR, PAIR, int> cur;
    checked[red.X][red.Y][blue.X][blue.Y] = 1;
    Q.push(make_tuple(red, blue, 0));                       // 좌표, 좌표, 움직인 횟수
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        red = get<0>(cur);
        blue = get<1>(cur);
        mv = get<2>(cur);
        if (10 < mv + 1) return -1;
        for (int i=0; i<4; i++) {
            newRed = red, newBlue = blue;

            bool tilt = true;
            while (tilt && (board[newRed.X][newRed.Y] == Path || board[newBlue.X][newBlue.Y] == Path)) {
                tilt = false;
                /*
                    각각의 구슬이 mx[i], my[i] 방향으로 계속 이동(tilt)할 수 있는 조건
                        1. 현재 있는 곳이 Path
                        2. 이동할 좌표가 보드 안에 있고 Wall이 아님
                        3. 나머지 구슬이 구멍에 빠지지 않은 경우, 이동할 좌표와 나머지 구슬의 좌표가 같으면 안됨
                */
                if (board[newRed.X][newRed.Y] == Path && withinBox(newRed.X + mx[i], newRed.Y + my[i]) && board[newRed.X + mx[i]][newRed.Y + my[i]]
                    && !(board[newBlue.X][newBlue.Y] == Path && newRed.X + mx[i] == newBlue.X && newRed.Y + my[i] == newBlue.Y)) {
                    newRed.X += mx[i];
                    newRed.Y += my[i];
                    tilt = true;
                }
                if (board[newBlue.X][newBlue.Y] == Path && withinBox(newBlue.X + mx[i], newBlue.Y + my[i]) && board[newBlue.X + mx[i]][newBlue.Y + my[i]]
                    && !(board[newRed.X][newRed.Y] == Path && newBlue.X + mx[i] == newRed.X && newBlue.Y + my[i] == newRed.Y)) {
                    newBlue.X += mx[i];
                    newBlue.Y += my[i];
                    tilt = true;
                }
            }

            if (board[newBlue.X][newBlue.Y] == Hole) continue;
            if (board[newRed.X][newRed.Y] == Hole) return mv + 1;
            if (board[newRed.X][newRed.Y] != Hole && !checked[newRed.X][newRed.Y][newBlue.X][newBlue.Y]) {
                checked[newRed.X][newRed.Y][newBlue.X][newBlue.Y] = 1;
                Q.push(make_tuple(newRed, newBlue, mv+1));
                /*
                    Debug line
                    printf("%s\t\tR(%d, %d) B(%d, %d)\n", i==0? "upward": i==1? "down" : i==2? "left" : "right", newRed.X, newRed.Y, newBlue.X, newBlue.Y);
                */
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%s", input);
        for (int j=0; j<M; j++) {
            if (!strncmp(&input[j], ".", 1)) board[i][j] = Path;
            else if (!strncmp(&input[j], "#", 1)) board[i][j] = Wall;
            else if (!strncmp(&input[j], "O", 1)) board[i][j] = Hole;
            else if (!strncmp(&input[j], "R", 1)) {
                board[i][j] = Path;
                red.X = i, red.Y = j;
            } else if (!strncmp(&input[j], "B", 1)) {
                board[i][j] = Path;
                blue.X = i, blue.Y = j;
            }
        }
    }
    printf("%d\n", sol());
    return 0;
}