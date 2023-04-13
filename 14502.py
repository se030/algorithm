import sys
from collections import deque
from itertools import combinations

WALL, VIRUS = 1, 2

N, M = map(int, sys.stdin.readline().split(' '))
_map = []
empty = []
for r in range(N):
    _map.append(list(map(int, sys.stdin.readline().strip().split(' '))))
    for c, value in enumerate(_map[r]):
        empty.append([r, c]) if value == 0 else None

visited = None
m = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def bfs(x, y):
    global _map, visited
    Q = deque([[x, y]])
    visited[x][y] = True
    res, flag = 1, True
    while Q:
        r, c = Q.popleft()
        for mr, mc in m:
            nr, nc = r + mr, c + mc
            if nr < 0 or N <= nr or nc < 0 or M <= nc or visited[nr][nc] or _map[nr][nc] == WALL:
                continue
            if _map[nr][nc] == VIRUS:
                flag = False
            elif _map[nr][nc] == 0:
                res += 1
            Q.append([nr, nc])
            visited[nr][nc] = True
    return res if flag else 0

def get_safe_area():
    global _map, visited
    res = 0
    visited = [[False for _ in range(M)] for _ in range(N)]
    for r in range(N):
        for c in range(M):
            if _map[r][c] == 0 and not visited[r][c]:
                res += bfs(r, c)
    return res

safe_area = 0
for comb in combinations(empty, 3):
    comb = list(comb)
    for r, c in comb:
        _map[r][c] = WALL
    safe_area = max(safe_area, get_safe_area())
    for r, c in comb:
        _map[r][c] = 0
print(safe_area)