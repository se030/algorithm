/*
    LIS binary search
        현재까지 나온 lis의 마지막 요소(tail) 기준으로
        dp 베열(lis)에는 유효한 lis (index) 저장
        prevIdx는 해당 요소가 속한 유효 lis 백트래킹 하기위한 배열
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[1000001], prevIdx[1000001], tail = -1;
vector<int> lis, ans;
void update(int idx) {
    int start = 0, lisEnd = lis.size()-1, end = lisEnd, mid;
    while (start + 1 < end) {
        mid = (start + end) / 2;
        if (arr[lis[mid]] < arr[idx]) start = mid;
        else end = mid;
    }
    if (arr[lis[start]] < arr[idx]) start++;
    prevIdx[idx] = lis[start - 1];
    lis[start] = idx;
    if (start == lisEnd) tail = idx;
}
int main() {
    scanf("%d", &N);
    memset(prevIdx, -1, sizeof(int) * N);
    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
        if (tail == -1? -2000000000 : arr[tail] < arr[i]) {
            prevIdx[i] = tail;
            tail = i;
            lis.push_back(tail);
        } else update(i);
    }

    int len = lis.size();
    printf("%d\n", len);
    while (true) {
        ans.push_back(arr[tail]);
        tail = prevIdx[tail];
        if (tail == -1) break;
    }
    for (int i=len-1; -1<i; i--) printf("%d ", ans[i]);
    printf("\n");

    return 0;
}