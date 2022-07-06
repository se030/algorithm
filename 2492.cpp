#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, T, K, x, y;
vector<pair<int, int>> jewels;
int sol() {
    int nx, ny, cnt, maxCnt = 0, ans_x, ans_y;
    for (auto a: jewels) {
    /*
        N, M 범위가 커서 max 100인 T를 활용해야 하는 풀이
        for (auto var: iterative container)
            auto: automatically identify the type of elements in range-expression
    */
        for (auto b: jewels) {
            x = min(a.first, b.first);
            y = min(a.second, b.second);
            nx = x + K;
            ny = y + K;
            if (N < nx) {
                x -= nx - N;
                nx = N;
            }
            if (M < ny) {
                y -= ny - M;
                ny = M;
            }
            cnt = 0;
            for (auto c: jewels) if (x <= c.first && c.first <= nx && y <= c.second && c.second <= ny) cnt++;
            if (maxCnt <= cnt) {
                maxCnt = cnt;
                ans_x = x;
                ans_y = ny;
            }
        }
    }
    printf("%d %d\n", ans_x, ans_y);
    return maxCnt;
}
int main() {
    scanf("%d %d %d %d", &N, &M, &T, &K);
    for (int i=0; i<T; i++) {
        scanf("%d %d", &x, &y);
        jewels.push_back({x, y});
    }
    sort(jewels.begin(), jewels.end());
    printf("%d\n", sol());
    return 0;
}