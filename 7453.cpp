#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, input[4000][4], lb, ub;
vector<int> A, C;
long long int ans = 0, cnt;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<4; j++) scanf("%d", &input[i][j]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A.push_back(input[i][0] + input[j][1]);     // A, B 배열에서 나오는 합의 조합
            C.push_back(input[i][2] + input[j][3]);     // C, D 배열에서 나오는 합의 조합
        }
    }
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    for (int i=0; i<A.size(); i++) {
        lb = lower_bound(C.begin(), C.end(), -A[i]) - C.begin();
        ub = upper_bound(C.begin(), C.end(), -A[i]) - C.begin();
        cnt = 1;
        while (i < A.size()-1 && A[i] == A[i+1]) cnt++, i++;

        if (C[lb] != -A[i]) continue;
        ans += cnt * (ub - lb);
    }
    printf("%lld\n", ans);
    return 0;
}