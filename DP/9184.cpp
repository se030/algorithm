#include <cstdio>
#include <cstdlib>
#include <cstring>

int ***W;
int w(int a, int b, int c) {    
    if (a <= 0 || b <= 0 || c <= 0) return W[0][0][0];
    else if (a > 20 || b > 20 || c > 20) return w(20,20,20);
    else if (W[a][b][c]) return W[a][b][c];
    else if (a < b && b < c) W[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    else W[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return W[a][b][c];
}

int main() {
    W = (int***)malloc(sizeof(int**)*21);
    for (int i=0; i < 21; i++) {
        W[i] = (int**)malloc(sizeof(int*)*21);
        for (int j = 0; j < 21; j++) {
            W[i][j] = (int*)malloc(sizeof(int)*21);
            memset(W[i][j], 0, sizeof(int)*21);
        }
    }
    W[0][0][0] = 1;
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) return 0;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}