import sys
from collections import deque

EMPTY, WALL, HOLE, R, B = '.', '#', 'O', 'R', 'B'

N, M = map(int, sys.stdin.readline().split(' '))
board, r, b, hole_x, hole_y = [], None, None, None, None
for row in range(N):
    board.append(list(sys.stdin.readline()))
    if R in board[row]:
        r = [row, board[row].index(R)]
    if B in board[row]:
        b = [row, board[row].index(B)]
    if HOLE in board[row]:
        hole_x, hole_y = [row, board[row].index(HOLE)]

def is_hole(x, y):
    return x == hole_x and y == hole_y
def is_valid_pos(x, y):
    return 0 <= x and x < N and 0 <= y and y < M
def is_movable(x, y, cx, cy):
    return is_valid_pos(x, y) and board[x][y] != WALL and (not (x == cx and y == cy) or is_hole(cx, cy))
m = [[0, 1], [0, -1], [1, 0], [-1, 0]]

ans = -1
Q = deque([[r, b, 0]])
visited = [[[[False for _ in range(10)] for _ in range(10)] for _ in range(10)] for _ in range(10)]
visited[r[0]][r[1]][b[0]][b[1]] = True
while Q:
    red, blue, count = Q.popleft()
    
    for mx, my in m:
        red_nx, red_ny = red
        blue_nx, blue_ny = blue
        while True:
            is_moving = False
            if not is_hole(red_nx, red_ny) and is_movable(red_nx + mx, red_ny + my, blue_nx, blue_ny):
                red_nx += mx
                red_ny += my
                is_moving = True
            if not is_hole(blue_nx, blue_ny) and is_movable(blue_nx + mx, blue_ny + my, red_nx, red_ny):
                blue_nx += mx
                blue_ny += my
                is_moving = True
            if not is_moving:
                break
        if (visited[red_nx][red_ny][blue_nx][blue_ny]) or (not is_hole(blue[0], blue[1]) and is_hole(blue_nx, blue_ny)):
            continue
        
        if is_hole(red_nx, red_ny):
            ans = min(ans, count + 1) if ans != -1 else count + 1
        if count + 1 < 10:
            Q.append([[red_nx, red_ny], [blue_nx, blue_ny], count + 1])
            visited[red_nx][red_ny][blue_nx][blue_ny] = True

print(ans)