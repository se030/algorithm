#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    vector<int> stuff(N);
    for (int i=0; i<N; i++) scanf("%d", &stuff[i]);

    int f = N/2, fSize = 1<<f, sSize = 1<<(N-f);
    vector<long long> first(fSize), second(sSize);
    for (int i=0; i<fSize; i++) for (int j=0; j<f; j++) if (i & (1<<j)) first[i] += stuff[j];
    for (int i=0; i<sSize; i++) for (int j=0; j<N-f; j++) if (i & (1<<j)) second[i] += stuff[f+j];
    sort(begin(first), end(first));
    sort(begin(second), end(second));

    int fIdx = 0, sIdx = sSize-1;
    long long ans = 0;
    while (fIdx < fSize && -1 < sIdx) {
        long long sum = first[fIdx]+second[sIdx];
        if (C < sum) sIdx--; // sum을 줄여야하는 경우
        else {
            long long fCnt = 1;
            while (fIdx+1 < fSize && first[fIdx] == first[fIdx+1]) {
                fIdx++;
                fCnt++;
            }
            ans += fCnt * (sIdx+1); // sIdx 이하 요소와 조합은 모두 가능
            fIdx++;
        }
    }
    printf("%lld\n", ans); // 아무것도 넣지 않는 경우도 포함하므로 제할 필요 없음
    return 0;
}