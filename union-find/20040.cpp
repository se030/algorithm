#include <cstdio>
#include <cstdlib>

int *p, ans, done;
int findF(int x) {
    if (p[x] == x) return x;
    p[x] = findF(p[x]);             // findF(p[x])인 점 주의
    return p[x];
}
void unionF(int x, int y, int N) {
    int _x = x < y? x : y;
    int _y = y < x? x : y;
    _x = findF(_x);
    _y = findF(_y);
    if (p[_x] == _y && !done) {
        ans = N;
        done = 1;
    }
    p[_x] = _y;
}
int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    p = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) p[i] = i;
    ans = 0;
    done = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        unionF(a, b, i);
    }
    printf("%d", ans);
    return 0;
}