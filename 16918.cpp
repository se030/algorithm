#include <cstdio>

int R, C, N, map[201][201]; // 빈 칸 -1

void sol() {
    int ni, nj, mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};

    while (N) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                map[i][j] += (map[i][j] == -1 ? 4 : -1);
            }
        }
        N--;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j]) continue;

                map[i][j] = -1;
                for (int k = 0; k < 4; k++) {
                    ni = i + my[k];
                    nj = j + mx[k];

                    if (0 <= ni && ni < R && 0 <= nj && nj < C) {
                        if (map[ni][nj]) map[ni][nj] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", map[i][j] == -1 ? '.' : 'O');
        }
        printf("\n");
    }

    return;
}

int main() {
    char temp;
    scanf("%d %d %d\n", &R, &C, &N);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%c", &temp);
            map[i][j] = (temp == '.' ? -1 : 2);
        }
        scanf("%c", &temp);
    }
    N--; // 아무것도 안하는 1초
    
    sol();
    return 0;
}