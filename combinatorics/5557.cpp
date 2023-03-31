/*
    idea. 중간 계산값으로 나올 수 있는 경우의 수가 0~20까지 21개
*/
#include <cstdio>
#include <cstring>
int N, res, num[100], cur, idx;
long long calc[2][21] = {0, };
long long sol() {
    calc[1][0] = 1;
    for (int n=0; n<N-1; n++) {
        cur = n % 2;
        memset(calc[cur], 0, sizeof(long long)*21);
        for (int i=0; i<21; i++) {
            idx = i + num[n];
            if (0 <= idx && idx <= 20) calc[cur][idx] += calc[!cur][i];
            if (0 < n) {
                idx = i - num[n];
                if (0 <= idx && idx <= 20) calc[cur][idx] += calc[!cur][i];
            }
        }
    }
    return calc[(N-2)%2][res];
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) scanf("%d", &num[i]);
    scanf("%d", &res);
    printf("%lld\n", sol());
    return 0;
}