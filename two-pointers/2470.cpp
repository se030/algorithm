#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {

    int N, *liq;
    scanf("%d", &N);
    liq = (int*)malloc(sizeof(int)*N);
    for (int i=0; i<N; i++) scanf("%d", &liq[i]);
    sort(&liq[0], &liq[N]);

    for (int i=0; i<N; i++) printf("%d ", liq[i]);
    printf("\n");

    int i = 0, j = N-1, ans_i, ans_j, _abs = 2000000001;
    while (i < j) {
        int sum = liq[i] + liq[j];
        if (abs(sum) < _abs) {
            _abs = abs(sum);
            ans_i = i;
            ans_j = j;
            if (_abs == 0) break;
        }
        if (sum < 0) i++;
        else j--;
    }

    printf("%d %d", liq[ans_i], liq[ans_j]);

    return 0;
}