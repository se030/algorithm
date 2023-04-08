import sys
from math import floor

N, M, K = map(int, sys.stdin.readline().split(' '))

# r, c, 질량, 방향, 속력
board = [[[] for _ in range(N)] for _ in range(N)]
for _ in range(M):
    r, c, m, s, d = map(int, sys.stdin.readline().split(' '))
    board[r - 1][c - 1].append([m, s, d])

D = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
def correctPosition(x):
    while x < 0:
        x += N
    while N <= x:
        x -= N
    return x
def move():
    global board
    # 이동
    new_board = [[[] for _ in range(N)] for _ in range(N)]
    for r in range(N):
        for c in range(N):
            for m, s, d in board[r][c]:
                mr, mc = D[d]
                nr, nc = correctPosition(r + s * mr), correctPosition(c + s * mc)
                new_board[nr][nc].append([m, s, d])
    # 연산
    for r in range(N):
        for c in range(N):
            if len(new_board[r][c]) < 2: # 한 칸에 두 개 이상일 때만
                continue
            
            sum_m, sum_s, flag, std = 0, 0, 0, new_board[r][c][0][2] % 2
            for m, s, d in new_board[r][c]:
                sum_m += m
                sum_s += s
                if std != d % 2:
                    flag = 1 # 1, 3, 5, 7
            nm, ns = floor(sum_m / 5), floor(sum_s / len(new_board[r][c]))
            new_board[r][c] = []
            
            if nm:
                for nd in [[0, 2, 4, 6], [1, 3, 5, 7]][flag]:
                    new_board[r][c].append([nm, ns, nd])
    board = new_board
    
while K:
    K -= 1
    move()

answer = 0
for r in range(N):
    for c in range(N):
        for fireball in board[r][c]:
            answer += fireball[0]
print(answer)