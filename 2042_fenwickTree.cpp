#include <cstdio>
#include <cstdlib>
long long N, M, K, S, a, b, c;
long long tree[1000001];

long long query(long long from, long long to) {
    long long ans = 0;
    while (to) {
        ans += tree[to];
        to -= (to & -to);
    }
    while (from) {
        ans -= tree[from];
        from -= (from & -from);
    }
    return ans;
}
void update(long long idx, long long val) {
    long long offset = val - query(idx-1, idx);
    while (idx <= N) {
        tree[idx] += offset;
        idx += (idx & -idx);
    }
}
int main() {
    scanf("%lld %lld %lld", &N, &M, &K);
    for (int i=1; i <= N; i++) scanf("%lld", &tree[i]);
    for (int i=1; i <= N; i++) {
        int p = i + (i & -i);
        if (p <= N) tree[p] = tree[p] + tree[i];
    }
    for (int i=0; i<M+K; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) update(b, c);
        if (a == 2) printf("%lld\n", query(b-1, c));
    }
    return 0;
}