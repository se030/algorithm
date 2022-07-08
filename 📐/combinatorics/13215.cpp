/*
    nCk 정의 수식에서 분모 소거
*/
#include <cstdio>
int M, peb[51], N = 0, K;
double sol() {
    double same = 0, total = 1, temp;
    for (auto p: peb) {
        temp = 0;
        if (K <= p) {
            temp = 1;
            for (int i=0; i<K; i++) temp *= (p - i);
        }
        same += temp;
    }
    for (int i=0; i<K; i++) total *= (N - i);
    return same / total;
}
int main() {
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &peb[i]);
        N += peb[i];
    }
    scanf("%d", &K);
    printf("%.15lf\n", sol());
    return 0;
}