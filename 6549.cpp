#include <cstdio>
#include <vector>
using namespace std;
int n, hist;
long long sol() {
    int idx = 0;
    long long ans = 0;
    vector<long long> height, pos;
    height.push_back(0);        // 지금까지 들어온 height 중 필요한 값들(오름차순)
    pos.push_back(0);           // height-histogram의 오른쪽 끝
    while (idx < n) {
        idx++;
        scanf("%d", &hist);
        while (hist < height.back()) {
            pos.pop_back();
            ans = max(ans, height.back() * (idx - 1 - pos.back()));
            height.pop_back();
        }
        height.push_back(hist);
        pos.push_back(idx);
    }
    for (int i=1; i<height.size(); i++)
        ans = max(ans, height[i] * (idx - pos[i-1]));
    return ans;
}
int main() {
    while (true) {
        scanf("%d", &n);
        if (!n) return 0;
        printf("%lld\n", sol());
    }
}