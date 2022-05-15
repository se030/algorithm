/*
감소수열의 경우, 수열을 뒤집으면 증가수열을 구하는 것과 같습니다.

upper[x] 는 0~x까지의 최장 증가수열의 길이,

lower[x] 는 x~끝까지의 최장 감소수열의 길이입니다
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>base(n);
    for(auto& i : base) cin >> i;

    // 이거를 N개에 대해 모두 구해서 그 중에 최대를 구해야!
    // 나는 LIS를 먼저 구해버려서 5 4 3 2 3 같은 케이스를 못잡아냈음
    vector<int> upper(n+1);
    vector<int> lower(n+1);
    for (int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(base[j] < base[i]){
                upper[i] = max(upper[i], upper[j]);
            }
        }
        upper[i]++;
    }
    for(int i = n-1; i >= 0; i--){
        for (int j = n-1; j > i; j--){
            if (base[j]<base[i]){
                lower[i] = max(lower[i], lower[j]);
            }
        }
        lower[i]++;
    }    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, lower[i] + upper[i]);
    }
    
    cout << ans-1;
}