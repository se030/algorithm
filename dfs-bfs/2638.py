import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split(' '))
square = []
for _ in range(N):
    square.append(list(map(int, sys.stdin.readline().split(' '))))

cheese, count = None, None
m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
def bfs_edge():
    global square, cheese, count
    cheese, count = [], [[0 for _ in range(M)] for _ in range(N)]
    
    Q = deque([[0, 0]])
    visited = [[False for _ in range(M)] for _ in range(N)]
    visited[0][0] = True
    while Q:
        x, y = Q.popleft()
        for mx, my in m:
            nx, ny = x + mx, y + my
            if nx < 0 or N <= nx or ny < 0 or M <= ny:
                continue
            if square[nx][ny]:
                count[nx][ny] += 1
            if not visited[nx][ny]:
                visited[nx][ny] = True
                cheese.append([nx, ny]) if square[nx][ny] else Q.append([nx, ny])
def melt():
    global square, cheese, count
    for x, y in cheese:
        if 2 <= count[x][y]:
            square[x][y] = 0

clock = 0
while True:
    bfs_edge()
    if not cheese:
        break
    melt()
    clock += 1
    
print(clock)