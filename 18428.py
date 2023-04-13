import sys
from itertools import combinations

S, T, X, O = 'S', 'T', 'X', 'O'

N = int(sys.stdin.readline())
_map, teachers, empty = [], [], []
for r in range(N):
    _map.append(sys.stdin.readline().strip().split(' '))
    for c, x in enumerate(_map[r]):
        if x == T:
            teachers.append([r, c])
        elif x == X:
            empty.append([r, c])

m = [[0, 1], [0, -1], [1, 0], [-1, 0]]
def out_of_bound(r, c):
    return r < 0 or N <= r or c < 0 or N <= c
def hid():
    for r, c in teachers:
        for mr, mc in m:
            nr, nc = r, c
            while True:
                nr, nc = nr + mr, nc + mc
                if out_of_bound(nr, nc) or _map[nr][nc] == O or _map[nr][nc] == T:
                    break
                if _map[nr][nc] == S:
                    return False
    return True

flag = False
for comb in combinations(empty, 3):
    for r, c in list(comb):     
        _map[r][c] = O
    if hid():
        flag = True
        break
    for r, c in list(comb):     
        _map[r][c] = X

print('YES' if flag else 'NO')