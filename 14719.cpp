#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int H, W, b, max_h = 501, ans = 0;
    vector<int> blocks;
    scanf("%d %d", &H, &W);
    for (int i=0; i<W; i++) {
        scanf("%d", &b);
        if (i == 0) max_h = b;
        else if (i == W-1) {
            if (b < max_h) {
                max_h = min(max_h, b);
                while (!blocks.empty()) {
                    if (blocks.back() < max_h) ans += max_h - blocks.back();
                    else max_h = blocks.back();
                    blocks.pop_back();
                }
            } else {
                while (!blocks.empty()) {
                    ans += max_h - blocks.back();
                    blocks.pop_back();
                }
            }
        } else if (max_h <= b) {
            while (!blocks.empty()) {
                ans += max_h - blocks.back();
                blocks.pop_back();
            }
            max_h = b;
        } else if (b < max_h) blocks.push_back(b);
    }
    printf("%d\n", ans);
    return 0;
}