// 증가하는 규칙이 피보나치와 동일함
#include <cstdio>
int N, C[1000001] = {0, };
int sol(int n) {
    if (C[n]) return C[n];
    else return (C[n] = (sol(n-2)%15746 + sol(n-1)%15746) % 15746);
}
int main() {
    scanf("%d", &N);
    C[1] = 1;
    C[2] = 2;
    printf("%d", sol(N));
    return 0;
}