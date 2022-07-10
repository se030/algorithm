#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, player[500001], tree[500001] = { 0, }, ranking;
vector<int> skill;
int query(int to) {
    int ans = 0;
    while (to) {
        ans += tree[to];
        to -= (to & -to);
    }
    return ans;
}
void update(int idx, int val) {
    while (idx <= N) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &player[i]);
        skill.push_back(player[i]);
    }
    sort(skill.begin(), skill.end());
    for (int i=1; i<=N; i++) {
        ranking = lower_bound(skill.begin(), skill.end(), player[i]) - skill.begin();
        update(ranking + 1, 1);
        printf("%d\n", i - query(ranking));
    }
    return 0;
}