import sys
from itertools import combinations
from collections import deque

room = []
for _ in range(5):
    room.append(sys.stdin.readline())

answer = 0
m = [[-1, 0], [1, 0], [0, -1], [0, 1]]
for c in combinations(range(25), 7):
    c = list(c)
    for i in range(7):
        c[i] = [c[i] // 5, c[i] % 5]

    count = 0
    for x, y in c:
        if room[x][y] == 'S':
            count += 1
    if count < 4:
        continue
    
    Q = deque([c.pop()])
    while Q:
        x, y = Q.popleft()
        for mx, my in m:
            nx = x + mx
            ny = y + my
            if [nx, ny] in c:
                c.remove([nx, ny])
                Q.append([nx, ny])
    if not c:
        answer += 1
        
print(answer)