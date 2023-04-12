import sys

N, M, x, y, K = map(int, sys.stdin.readline().split(' '))

_map, dice = [], [0 for _ in range(7)]
for _ in range(N):
    _map.append(list(map(int, sys.stdin.readline().split(' '))))
directions = list(map(int, sys.stdin.readline().split(' ')))

def roll(d):
    if d == 1:
        dice[1], dice[3], dice[6], dice[4] = dice[4], dice[1], dice[3], dice[6]
    elif d == 2:
        dice[1], dice[3], dice[6], dice[4] = dice[3], dice[6], dice[4], dice[1]
    elif d == 3:
        dice[1], dice[2], dice[6], dice[5] = dice[5], dice[1], dice[2], dice[6]
    elif d == 4:
        dice[1], dice[2], dice[6], dice[5] = dice[2], dice[6], dice[5], dice[1]

m = [[0, 1], [0, -1], [-1, 0], [1, 0]] # 동서남북
for d in directions:
    mx, my = m[d - 1]
    nx, ny = x + mx, y + my
    if nx < 0 or N <= nx or ny < 0 or M <= ny:
        continue
    roll(d)
    print(dice[1])
    x, y = nx, ny
    if _map[x][y]: # 쓰여있는 수가 주사위 바닥면으로 복사, 칸은 0
        dice[6] = _map[x][y]
        _map[x][y] = 0
    else: # 주사위 바닥면의 수가 칸으로 복사
        _map[x][y] = dice[6]