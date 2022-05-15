#include <cstdio>
#include <algorithm>
using namespace std;
int N, arr[1000], dp[1000];
void sol() {
    int maxv, ret = 1;
    dp[0] = 1;
    for (int i=0; i<N; i++) {
        maxv =  0;
        for (int j=0; j<i; j++)
            if (arr[i] > arr[j]) maxv = max(maxv, dp[j]);
        dp[i] = maxv + 1;
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &arr[i]);
    sol();
    return 0;
}

/*
binary search

#include <cstdio>
#include <cstdlib>
#include <cstring>
int main() {
    int N, *A;
    scanf("%d", &N);
    A = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    int *dp = (int*)malloc(sizeof(int)*N);
    int ans = 1;
    memset(dp, 0, sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        int start = 0, end = ans;
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (A[i] <= dp[mid]) end = mid;
            else start = mid;
        }
        dp[end] = A[i];
        if (end == ans) ans++;
    }
    printf("%d", ans-1);
    return 0;
}

*/