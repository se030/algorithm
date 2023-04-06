import sys
from collections import deque

sys.setrecursionlimit(10**5)

N = int(sys.stdin.readline())

map = []
for _ in range(N):
    map.append(str(sys.stdin.readline()))

m = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def dfs(x, y, color, isSame):
    global visited
    visited[x][y] = True
    
    for mx, my in m:
        nx, ny = x + mx, y + my
        if nx < 0 or N - 1 < nx or ny < 0 or N - 1 < ny:
            continue
        if not visited[nx][ny] and isSame(color, map[nx][ny]):
            dfs(nx, ny, color, isSame)

visited = [[False for _ in range(N)] for _ in range(N)]
def isSameForNormal(a, b):
    return a == b

count1 = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            count1 += 1
            dfs(i, j, map[i][j], isSameForNormal)

visited = [[False for _ in range(N)] for _ in range(N)]
def isSameForWeak(a, b):
    if a in ['R', 'G'] and b in ['R', 'G']:
        return True
    return a == b

count2 = 0
for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            count2 += 1
            dfs(i, j, map[i][j], isSameForWeak)

print(f'{count1} {count2}')