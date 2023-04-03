import sys
from math import floor

R, C, T = map(int, sys.stdin.readline().split(' '))

room, cleaner = [], None
for r in range(R):
    row = list(map(int, sys.stdin.readline().split(' ')))
    room.append(row)
    if -1 in row and cleaner == None:
        cleaner = r

m = [[-1, 0], [1, 0], [0, -1], [0, 1]]
def unspreadable(x, y):
    global R, C, room
    return x < 0 or R <= x or y < 0 or C <= y or room[x][y] == -1
def spread():
    global room
    updated_room = [row[:] for row in room]
    for r in range(R):
        for c in range(C):
            if room[r][c] <= 0:
                continue
            s = floor(room[r][c] / 5)
            for x, y in m:
                nr = r + x
                nc = c + y
                if unspreadable(nr, nc):
                    continue
                updated_room[r][c] -= s
                updated_room[nr][nc] += s
    room = updated_room

# 공기청정기 위치는 [cleaner, 0], [cleaner + 1, 0]
def clean():
    global room, cleaner
    
    # 위
    for r in range(cleaner - 1, 0, -1):
        room[r][0] = room[r - 1][0]
    for c in range(C - 1):
        room[0][c] = room[0][c + 1]
    for r in range(0, cleaner):
        room[r][C - 1] = room[r + 1][C - 1]
    for c in range(C - 1, 1, -1):
        room[cleaner][c] = room[cleaner][c - 1]
    room[cleaner][1] = 0
    
    # 아래
    for r in range(cleaner + 2, R - 1):
        room[r][0] = room[r + 1][0]
    for c in range(C - 1):
        room[R - 1][c] = room[R - 1][c + 1]
    for r in range(R - 1, cleaner + 1, -1):
        room[r][C - 1] = room[r - 1][C - 1]
    for c in range(C - 1, 1, -1):
        room[cleaner + 1][c] = room[cleaner + 1][c - 1]
    room[cleaner + 1][1] = 0

while (T):
    T -= 1
    spread()
    clean()

print(sum(map(sum, room)) + 2)