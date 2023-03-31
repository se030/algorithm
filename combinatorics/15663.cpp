#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, M, d;
vector<int> num;
set<vector<int>> ans;
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        scanf("%d", &d);
        num.push_back(d);
    }
    sort(num.begin(), num.end());
    do {
        vector<int> temp;
        for (int i=0; i<M; i++) temp.push_back(num[i]);
        ans.insert(temp);
    } while (next_permutation(num.begin(), num.end()));
    for (auto p: ans) {
        for (auto n: p) printf("%d ", n);
        printf("\n");
    }
    return 0;
}