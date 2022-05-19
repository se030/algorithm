#include <cstdio>
#include <algorithm>
using namespace std;
int n, bamboo[500][500], dp[500][500],
    mx[] = {1, 0, -1, 0},
    my[] = {0, 1, 0, -1};
int dfs(int x, int y) {
    if (dp[x][y] == -1) {
        int path = 0;
        for (int i=0; i<4; i++) {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
                if (bamboo[x][y] < bamboo[nx][ny]) path = max(path, dfs(nx, ny));
        }
        dp[x][y] = path;
    }
    return 1 + dp[x][y];
}
void sol() {
    int ans;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) ans = max(ans, dfs(i,j));
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &bamboo[i][j]);
            dp[i][j] = -1;
        }
    }
    sol();
    return 0;
}