#include <cstdio>
#include <cstdlib>
int *p, *cnt;
int findF(int a) {
    if (a == p[a]) return a;
    p[a] = findF(p[a]);
    return p[a];
}
void unionF(int a, int b) {
    a = findF(a);
    b = findF(b);
    if (p[a] != b) {
        p[a] = b;
        cnt[b] += cnt[a];
    }
}
int main() {
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    p = (int*)malloc(sizeof(int)*(N+1));
    cnt = (int*)malloc(sizeof(int)*(N+1));
    for (int i=1; i<=N; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        unionF(x, y);
    }
    printf("%d", cnt[findF(1)]-1);
    return 0;
}