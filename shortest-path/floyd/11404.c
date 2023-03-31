#include <stdio.h>
#include <stdlib.h>
#define INF 10000000

int n, m;
int dist[110][110];     // [i][j]: i에서 j로 가는 비용

void floyd() {
    for (int j=1; j<=n; j++) {          // 중간
        for (int i=1; i<=n; i++){       // 시작
            if (dist[i][j] == INF) continue;
            for (int k=1; k<=n; k++){   // 끝
                if (dist[j][k] == INF) continue;        // 경로가 없으면 skip
                if(dist[i][j]+dist[j][k] < dist[i][k])
                    dist[i][k] = dist[i][j]+dist[j][k];
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j) dist[i][j] = INF;
        }
    }

    for (int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c < dist[a][b]) dist[a][b] = c;
    }

    floyd();

    for (int i=1; i<=n; i++) {          // 중간
        for (int j=1; j<=n; j++){       // 시작
            if (dist[i][j] == INF) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}