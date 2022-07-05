// https://mathsciforstudent.tistory.com/118

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
        printf("end = %d, ans = %d\t\t", end, ans);
        for (int i=1; i < ans; i++) printf("%d ", dp[i]);
        printf("\n");
    }
    printf("%d", ans-1);
    return 0;
}