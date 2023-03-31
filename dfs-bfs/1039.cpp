#include <cstdio>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
int N, K, temp, M = 0;
int sol(int n, int k) {
    int offset_i, offset_j, num_i, num_j, ans = -1;    
    set<int> set_k = { n };
    while (k) {
        set<int> cur(set_k);
        set_k.clear();
        for (set<int>::iterator s = cur.begin(); s != cur.end(); s++) {
            for (int i=0; i<M-1; i++) {
                for (int j=i+1; j<M; j++) {
                    offset_i = (int)pow(10, i);
                    offset_j = (int)pow(10, j);
                    num_i = (*s / offset_i) % 10;
                    num_j = (*s / offset_j) % 10;
                    if (j == M-1 && num_i == 0) continue;
                    temp = *s + (num_i - num_j) * (offset_j - offset_i);
                    if (k == 1) ans = max(ans, temp);
                    else set_k.insert(temp);
                }
            }
        }
        k--;
    }
    return ans;
}
int main() {
    scanf("%d %d", &N, &K);
    temp = N;
    while (0 < temp) {
        temp /= 10;
        M++;
    }
    printf("%d\n", sol(N, K));
    return 0;
}