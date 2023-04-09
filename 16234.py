import sys
from collections import deque
sys.setrecursionlimit(2500)

N, L, R = map(int, sys.stdin.readline().split(' '))
population, visited, union = [], None, []
for _ in range(N):
    population.append(list(map(int, sys.stdin.readline().split(' '))))

def is_within_map(r, c):
    global N
    return 0 <= r and r < N and 0 <= c and c < N
def is_union(cur, next):
    global population
    r, c, = cur
    nr, nc = next
    diff = abs(population[r][c] - population[nr][nc])
    return L <= diff and diff <= R

m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
def create_union(r, c):
    global population, visited, union
    
    union.append([r, c])
    visited[r][c], sum = True, population[r][c]
    
    for mr, mc in m: 
        nr, nc = r + mr, c + mc
        if is_within_map(nr, nc) and not visited[nr][nc] and is_union([r, c], [nr, nc]):
            sum += create_union(nr, nc)
    
    return sum

def move_union(sum):
    global population, union
    if len(union) <= 1:
        union = []
        return 0
    res = int(sum / len(union))
    for r, c in union:
        population[r][c] = res
    union = []
    return 1

def move():
    global N, population, visited
    visited = [[False for _ in range(N)] for _ in range(N)]
    flag = 0
    for r in range(N):
        for c in range(N):
            if not visited[r][c]:
                sum = create_union(r, c)
                flag |= move_union(sum)
    return True if flag else False
    
day = 0
while True:
    moved = move()
    if not moved:
        break
    day += 1

print(day)
