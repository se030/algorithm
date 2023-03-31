/*
    "답이 x이상일 수 있는가?"라는 질문에 대답할 수 있다면 어떻게 될까요.
    답이 x이상이 아니다 -> 답이 x보다 작은 범위를 탐색
    답이 x이상이다 -> 답이 x이상인 범위를 탐색
    이므로 이분 검색을 이용해 해결할 수 있습니다.
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int N, C, *x, *dist;
    scanf("%d %d", &N, &C);
    x = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) scanf("%d", &x[i]);
    sort(&x[0], &x[N]);
    int lo = 1, hi = 1000000000;
    while (lo + 1 < hi) {
        int mid = (lo+hi)/2, idx = 1, c = 1;
        while (idx < N) {
            int dist = 0;
            while (idx < N && dist < mid) {
                dist += x[idx] - x[idx - 1];
                idx++;
            }
            if (mid <= dist) c++;
        }
        if (c < C) hi = mid;
        else lo = mid;
    }
    printf("%d", lo);    
    return 0;
}