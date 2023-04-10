import sys
from collections import deque

R, C = map(int, sys.stdin.readline().split(' '))
kkung = []
for _ in range(R):
    kkung.append(sys.stdin.readline().strip())

visited = [[False for _ in range(C)] for _ in range(R)]
m = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def bfs(x, y):
    Q = deque([[x, y]])
    visited[x][y] = True
    v_count, k_count = 0, 0
    
    while Q:
        r, c = Q.popleft()
        if kkung[r][c] == 'v':
                v_count += 1
        elif kkung[r][c] == 'k':
            k_count += 1
            
        for mr, mc in m:
            nr, nc = r + mr, c + mc
            if nr < 0 or R <= nr or nc < 0 or C <= nc or kkung[nr][nc] == '#' or visited[nr][nc]:
                continue
            Q.append([nr, nc])
            visited[nr][nc] = True       
             
    return [v_count, k_count]        

V, K = 0, 0
for r in range(R):
    for c in range(C):
        if visited[r][c] or kkung[r][c] == '#':
            continue
        else:
            v, k = bfs(r, c)
            if v == 0 and k == 0:
                continue
            if v < k:
                K += k
            else:
                V += v

print(K, V)