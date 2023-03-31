#include <cstdio>
#include <vector>
#include <queue>
#define MAX_STATION 10001
using namespace std;
int T, N, M, S, E, A[1001];

void sol(int t) {
    vector<vector<int>>
        line(1001, vector<int>()),          // 노선 별 역 정보
        station(10001, vector<int>());      // 역 별 노선 정보
    
    vector<int> transfer(1001, MAX_STATION);
    queue<int> Q;
    int cur, s, l, ans = MAX_STATION;

    scanf("%d %d %d %d", &N, &M, &S, &E);
    for (int m=1; m<=M; m++) scanf("%d", &A[m]);
    for (int m=1; m<=M; m++) {
        for (int i=0; i<A[m]; i++) {
            scanf("%d", &s);
            line[m].push_back(s);
            station[s].push_back(m);
        }
    }

    for (int i=0; i<station[S].size(); i++) {
        Q.push(station[S][i]);
        transfer[station[S][i]] = 0;
    }
    while (Q.size()) {
        cur = Q.front();
        Q.pop();
        for (int i=0; i<line[cur].size(); i++) {
            s = line[cur][i];
            for (int j=0; j<station[s].size(); j++) {
                l = station[s][j];
                if (l != cur && transfer[cur] + 1 <= transfer[l]) {
                    transfer[l] = transfer[cur] + 1;
                    Q.push(l);
                }
            }
        }
    }
    for (int i=0; i<station[E].size(); i++) ans = min(ans, transfer[station[E][i]]);
    printf("#%d %d\n", t, ans == MAX_STATION? -1 : ans);
}

int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) sol(t);
    return 0;
}