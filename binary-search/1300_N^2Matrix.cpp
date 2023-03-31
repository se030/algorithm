#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    long long N, k;
    scanf("%lld %lld", &N, &k);

    long long lo = 1, hi = k;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        /*
            mid보다 작거나 같은 수의 개수가 k 이상이어야 함
            행마다 x < mid 만족하는 x의 개수는 mid/i 또는 N 중 더 작은 값
            https://kbw1101.tistory.com/29
        */
        long long cnt = 0;
        for (int i = 1; i <= N; i++) cnt += min(mid/i, N);
        
        if (cnt < k) lo = mid;
        else hi = mid;
    }
    printf("%lld", hi);
    return 0;
}