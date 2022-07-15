#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 10001
#define MOD 1000000007
using namespace std;
int N, arr[MAX_N], cur, pre,
    dp[2][MAX_N] = { 0, };      // 제단 i의 높이가 j를 만족하는 경우의 수, 직전 제단 데이터만 있으면 구할 수 있음
int sol() {
    dp[0][0] = 1;               // cf) 첫 입력이 불가능한 경우 0임 ㅠㅠ line34에서 처리
    for (int i=1; i<N; i++) {
        cur = i % 2;
        pre = (i-1) % 2;
        memset(dp[cur], 0, sizeof(int)*N);
        if (arr[i] == -1) {
            for (int j=0; j <= min(i, (N-1)-i); j++) {
                dp[cur][j] = ((dp[pre][j]
                    + (N <= j + 1? 0 : dp[pre][j + 1])) % MOD
                    + (j - 1 < 0? 0 : dp[pre][j - 1])) % MOD;
            }
        } else {
            dp[cur][arr[i]] = ((dp[pre][arr[i]]
                + (N <= arr[i] + 1? 0 : dp[pre][arr[i] + 1])) % MOD
                + (arr[i] - 1 < 0? 0 : dp[pre][arr[i] - 1])) % MOD;
        }
    }

    return dp[(N-1)%2][0];
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > min(i, (N-1)-i)) {
            printf("0\n");
            return 0;
        }
	}
    printf("%d\n", sol());
    return 0;
}

/*
    dp는 아이디어가 진짜 ..🥹 언젠간 잘하겠지 ...
    https://mapocodingpark.blogspot.com/2020/03/BOJ-5626.html
*/