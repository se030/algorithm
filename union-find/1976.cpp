#include <cstdio>
#include <cstdlib>

int *p;
int findF(int a) {
    if (a == p[a]) return a;
    p[a] = findF(p[a]);
    return p[a];    // p배열을 연결된 최상위 노드로 update! memoization 해줘야 timeout 안남
}
void unionF(int a, int b) {
    a = findF(a);
    b = findF(b);
    p[a] = b;
}

int main() {
    int N, M, input;
    scanf("%d %d", &N, &M);
    p = (int*)malloc(sizeof(int) * (N+1));
    for (int i=1; i <= N; i++) p[i] = i;
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= N; j++) {
            scanf("%d", &input);
            if (input) unionF(i < j? i:j, i < j? j:i);
        }
    }
    scanf("%d", &input);
    int parent = findF(input);
    for (int i=1; i < M; i++) {
        scanf("%d", &input);
        if (findF(input) != parent) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}