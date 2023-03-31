/*
    N개의 정수로 이루어진 수열
    크기가 양수인 부분수열 중 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수

    1. 앞 배열과 뒷 배열로 나누어 각각의 부분합 집합을 만들고
    2. 두 배열을 투포인터 탐색하며 합이 S가 되는 경우의 수를 구함
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    vector<int> nums(N);    // 입력된 수열
    for (int i=0; i<N; i++) scanf("%d", &nums[i]);
    int f = N / 2, fSize = 1 << f, sSize = 1 << (N-f);
    vector<int> first_half(fSize), second_half(sSize);

    // 2^n 개의 부분집합, 비트마스킹으로 부분집합의 합 구하기
    for (int i=0; i < fSize; i++) for (int j=0; j < f; j++) if (i & (1<<j)) first_half[i] += nums[j];
    for (int i=0; i < sSize; i++) for (int j=0; j < N-f; j++) if (i & (1<<j)) second_half[i] += nums[f + j];
    sort(begin(first_half), end(first_half));
    sort(begin(second_half), end(second_half));

    // 투포인터 탐색
    int fIdx = 0, sIdx = sSize-1;
    long long ans = 0;
    while (fIdx < fSize && -1 < sIdx) {
        int sum = first_half[fIdx] + second_half[sIdx];
        if (sum < S) fIdx++;
        else if (S < sum) sIdx--;
        else {
            long long fCnt = 1, sCnt = 1;
            while (fIdx+1 < fSize && first_half[fIdx] == first_half[fIdx+1]) {
                fIdx++;
                fCnt++;
            }
            while (-1 < sIdx-1 && second_half[sIdx] == second_half[sIdx-1]) {
                sIdx--;
                sCnt++;
            }
            ans += fCnt*sCnt;
            fIdx++;
            sIdx--;
        }
    }

    // 예외 처리, S=0일 때는 공집합 끼리의 합을 하나 제함
    printf("%lld", S == 0? ans-1 : ans);
    return 0;
}