#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int T, n, m, A[1001] = { 0, }, B[1001] = { 0, };
vector<int> subA, subB;
int main() {
    scanf("%d\n%d", &T, &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &A[i]);
        A[i] += A[i-1];
        for (int j=0; j<i; j++) subA.push_back(A[i] - A[j]);
    }
    scanf("%d", &m);
    for (int i=1; i<=m; i++) {
        scanf("%d", &B[i]);
        B[i] += B[i-1];
        for (int j=0; j<i; j++) subB.push_back(B[i] - B[j]);
    }
    sort(subA.begin(), subA.end());
    sort(subB.begin(), subB.end());
    int sizeA = subA.size(), sizeB = subB.size(), idxA = 0, idxB = sizeB-1, sum;
    long long cntA, cntB, ans = 0;
    while (idxA < sizeA && 0 <= idxB) {
        sum = subA[idxA] + subB[idxB];
        if (sum == T) {
            cntA = 1;
            cntB = 1;
            while (idxA + 1 < sizeA && subA[idxA + 1] == subA[idxA])
                cntA++, idxA++;
            while (0 <= idxB - 1 && subB[idxB - 1] == subB[idxB])
                cntB++, idxB--;
            ans += cntA * cntB;     // cf) 오버플로우
            idxA++, idxB--;
        } else if (sum < T) idxA++;
        else if (T < sum) idxB--;
    }
    printf("%lld\n", ans);
    return 0;
}