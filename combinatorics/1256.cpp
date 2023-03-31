#include <cstdio>
#include <cstdlib>
#include <cstring>
long long pascal[250][250];
int N, M;
void query(int a, int z, long long target, char* result, int next) {
    if (next == N+M) result[next] = '\0';
    else if (a != 0 && target <= pascal[a+z-1][z]) {
        result[next] = 'a';
        query(a-1, z, target, result, next+1);
    }
    else {
        result[next] = 'z';
        query(a, z-1, target-pascal[a+z-1][z], result, next+1);
    }
    return;
}
int main() {
    for (int i = 0; i<250; i++) memset(pascal[i], 0, sizeof(pascal[i]));
    long long K;
    scanf("%d %d %lld", &N, &M, &K);
    for (int i=0; i<=N+M+1; i++) {
        for (int j=0; j<=i; j++){
            if (i==j || j==0) pascal[i][j] = 1;
            else {
                if (pascal[i-1][j-1] + pascal[i-1][j] < 1000000000) pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                else pascal[i][j] = 1000000000;
            }
        }
    }
    if (pascal[N+M][N] < K) {
        printf("-1\n");
        return 0;
    }
    char* string = (char*)malloc(sizeof(char)*(N+M+1));
    query(N, M, K, string, 0);
    printf("%s\n", string);
    return 0;
}