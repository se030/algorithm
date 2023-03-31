#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
int T, l, visited[300][300], x, y, dx, dy,
    mx[] = {-2, -1, 1, 2, -2, -1, 2, 1},
    my[] = {-1, -2, -2, -1, 1, 2, 1, 2},
    nx, ny;
int sol(int x, int y, int dx, int dy) {
    queue<pair<pair<int, int>,int>> map; // x, y, #move
    map.push({{x, y}, 0});
    visited[x][y] = 1;
    while (map.size()) {
        pair<pair<int, int>, int> cur = map.front();
        map.pop();
        if (cur.first.first == dx && cur.first.second == dy) return cur.second;
        for (int m=0; m<8; m++) {
            nx = cur.first.first + mx[m];
            ny = cur.first.second + my[m];
            if (0 <= nx && nx < l && 0 <= ny && ny < l && !visited[nx][ny]) {
                map.push({{nx, ny}, cur.second+1});
                visited[nx][ny] = 1;
            }
        }
    }
}
int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        scanf("%d\n%d %d\n%d %d", &l, &x, &y, &dx, &dy);
        for (int i=0; i<l; i++) memset(visited[i], 0, sizeof(int)*l);
        printf("\n%d", sol(x, y, dx, dy));
    }
    return 0;
}