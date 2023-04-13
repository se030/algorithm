import sys
from collections import deque

n, pos, visited = None, None, None

def isReachable(start, end):
    return (abs(start[0] - end[0]) + abs(start[1] - end[1])) <= 1000
def sol():
    global visited
    edge = [[] for _ in range(n + 2)]
    for i in range(n + 2):
        for j in range(i + 1, n + 2):
            if isReachable(pos[i], pos[j]):
                edge[i].append(j)
                edge[j].append(i)

    Q = deque([0]) # home
    visited[0] = True
    while Q:
        cur = Q.popleft()
        for v in edge[cur]:
            if visited[v]:
                continue
            Q.append(v)
            visited[v] = True

t = int(sys.stdin.readline())
for _ in range(t):    
    n = int(sys.stdin.readline())
    pos = []
    visited = [False for _ in range(n + 2)]
    for _ in range(n + 2):
        pos.append(list(map(int, sys.stdin.readline().split(' '))))
    
    sol()
    print('happy' if visited[n + 1] else 'sad')