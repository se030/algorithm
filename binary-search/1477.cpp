#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, L, p;
vector<int> pos;

int count(int section) { // 간격 section으로 세워지는 휴게소 개수
    int cnt = 0;
    for (int i = 1; i < N + 2; i++) {
        int dist = pos[i] - pos[i-1];
        cnt += dist / section;
        if (!(dist % section)) cnt--;
    }
    return cnt;
}
int sol() {
    sort(pos.begin(), pos.end());
    int lo = 1, hi = L, mid, ans;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (M < count(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}
int main() {
    scanf("%d %d %d", &N, &M, &L);
    pos.push_back(0);
    pos.push_back(L);
    for (int i=0; i<N; i++) {
        scanf("%d", &p);
        pos.push_back(p);
    }
    printf("%d\n", sol());
    return 0;
}