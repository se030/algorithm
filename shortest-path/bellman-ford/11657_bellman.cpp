#include <cstdio>
#include <vector>
#include <tuple>
#define INF 1000000000
using namespace std;
int N, M, A, B, C;
long long int d[501];
vector<tuple<int, int, int>> bus;
void bf() {
    d[1] = 0;
    for (int i=2; i<=N; i++) d[i] = INF;
    // V-1번 * E개의 간선 확인 + 사이클 탐지를 위한 E개의 간선 확인
    for (int iter=0; iter<N; iter++) {

        for (int i=0; i<bus.size(); i++) {
            tuple<int, int, int> cur = bus[i];

            if (d[get<0>(cur)] != INF && d[get<0>(cur)]+get<2>(cur) < d[get<1>(cur)]) {
                d[get<1>(cur)] = d[get<0>(cur)]+get<2>(cur);
                // 음의 사이클 탐지
                if (iter == N-1) {
                    printf("%d\n", -1);
                    return;
                }
            }
        }
    }
    for (int i=2; i<=N; i++) printf("%lld\n", d[i] == INF? -1:d[i]);
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        bus.push_back(make_tuple(A, B, C));
    }
    bf();
    return 0;
}