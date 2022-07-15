#include <cstdio>
#include <cstring>
int N, M, a, b, w, p[100001] = { 0, }, parent, pa, pb;
long long offset[100001];
char q[2];
int findF(int a) {
    if (a != p[a]) {
        parent = findF(p[a]);
        offset[a] += offset[p[a]];
        p[a] = parent;
    }
    return p[a];
}
void unionF(int a, int b, int w) {
    pa = findF(a);
    pb = findF(b);
    if (pa == pb) return;       // *** 이미 비교가 가능하면 리턴해주어야 함
    p[pb] = pa;
    offset[pb] = offset[a] - offset[b] + w;
}
int main() {
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M ==0) break;
        for (int i=1; i<=N; i++) {
            p[i] = i;
            offset[i] = 0;
        }
        for (int i=0; i<M; i++) {
            scanf("%s", q);
            scanf("%d %d", &a, &b);
            if (!strncmp(q, "?", 1)) {
                if (findF(a) == findF(b))
                    printf("%lld\n", offset[b] - offset[a]);
                else printf("UNKNOWN\n");
            } else {
                scanf("%d", &w);
                unionF(a, b, w);
            }
        }
    }
    return 0;
}