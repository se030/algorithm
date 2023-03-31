#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {

    int N, start = 0, end = 1, sum = 2, res = 0;
    bool *nums;
    vector<int> prime;

    scanf("%d", &N);

    nums = (bool*)malloc(sizeof(bool)*(N+1));
    memset(nums, 0, sizeof(nums));
    for (int i = 2; i <= N; i++) {
        if (nums[i] == 0) {
            prime.push_back(i);

            for (int j = i; j <= N; j += i) {
                nums[j] = 1;
            }
        }
    } // 에라토스테네스의 체, 전체 범위에서 i=2부터 시작해 배수를 모두 지우기

    for (int i=0; i<prime.size(); i++) printf("%d ", prime[i]);
    printf("\n");

    while (end <= prime.size() && start <= end) {
        if (sum < N) sum += prime[end++];
        else {
            if (sum == N) res += 1;
            sum -= prime[start++];
        }
    }

    printf("%d", res);

    return 0;
}