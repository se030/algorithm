#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int N, D, from, to, len, dist[10001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
void sol() {
    for (int i=0; i<=D; i++) dist[i] = i;
    while (Q.size()) {
        tuple<int,int,int> cur = Q.top();
        Q.pop();
        if (get<0>(cur) <= D && dist[get<1>(cur)] + get<2>(cur) < dist[get<0>(cur)]) {
            dist[get<0>(cur)] = dist[get<1>(cur)] + get<2>(cur);
            for (int i=get<0>(cur)+1; i<=D; i++)
                dist[i] = min(dist[i], dist[get<0>(cur)] + (i-get<0>(cur)));
        }
    }
    printf("%d\n", dist[D]);
}
int main() {
    scanf("%d %d", &N, &D);
    for (int i=0; i<N; i++) {
        scanf("%d %d %d", &from, &to, &len);
        Q.push(make_tuple(to, from, len));
    }
    sol();
    return 0;
}