import sys
from collections import deque
from heapq import heapify

N = int(sys.stdin.readline())

space, baby = [], None
for r in range(N):
    row = list(map(int, sys.stdin.readline().split(' ')))
    space.append(row)
    if 9 in row:
        baby = [r, row.index(9)]

weight, ate, candidates, dist, MAX_DIST = 2, 0, None, None, 1000
m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
def search():
    global space, baby, weight, candidates, dist
    
    candidates = []
    dist = [[MAX_DIST for _ in range(N)] for _ in range(N)]
    dist[baby[0]][baby[1]] = 0
    Q = deque([baby])
    
    while Q:
        r, c  = Q.popleft()
        for mr, mc in m:
            nr, nc = r + mr, c + mc
            
            if nr < 0 or N <= nr or nc < 0 or N <= nc or baby == [nr, nc]:
                continue
            new_dist = dist[r][c] + 1
            is_visited = dist[nr][nc] != MAX_DIST and dist[nr][nc] <= new_dist
            if weight < space[nr][nc] or is_visited: # 못가거나 안가도 되는 곳
                continue
            
            if space[nr][nc] != 0 and space[nr][nc] < weight:
                candidates.append([new_dist, nr, nc])
            else:
                Q.append([nr, nc])
            dist[nr][nc] = new_dist
    
def hunt():
    global space, baby, weight, ate, candidates, dist
    heapify(candidates) 
    prey = candidates[0]
    dist, nr, nc = prey
    
    space[baby[0]][baby[1]] = 0
    baby = [nr, nc]
    space[nr][nc] = 9
    
    ate += 1
    if ate == weight:
        weight += 1
        ate = 0

    return dist

clock = 0
while True:
    search()
    if not candidates:
        break
    dist = hunt()
    clock += dist # 이거를 그냥 1씩 더함 .. 문제 제대로 읽기
    
print(clock)