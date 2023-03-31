#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int n, *a, x;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(&a[0], &a[n]);
    scanf("%d", &x);

    int first = 0, second = n-1, ans = 0;
    while (first != second) {
        int sum = a[first] + a[second];
        if (sum == x) {
            ans++;
            first++;
        }
        else if (x < sum) second--;
        else first++;
    }

    printf("%d", ans);

    return 0;
}