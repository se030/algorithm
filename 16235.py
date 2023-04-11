import sys

N, M, K = map(int, sys.stdin.readline().split(' '))
A, land = [], [[[] for _ in range(N)] for _ in range(N)]
for _ in range(N):
    A.append(list(map(int, sys.stdin.readline().split(' '))))
for _ in range(M):
    x, y, z = map(int, sys.stdin.readline().split(' '))
    land[x - 1][y - 1].append(z)

a = [[5 for _ in range(N)] for _ in range(N)]
m = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
def seasons():
    autumn = [[0 for _ in range(N)] for _ in range(N)]
    for r in range(N):
        for c in range(N):
            land[r][c].sort()
            
            dead = -1
            for idx in range(len(land[r][c])):
                tree = land[r][c][idx]
                if a[r][c] < tree:
                    dead = idx
                    break
                
                a[r][c] -= tree
                land[r][c][idx] += 1
                
                if not (land[r][c][idx] % 5):
                    for mr, mc in m:
                        nr, nc = r + mr, c + mc
                        if nr < 0 or N <= nr or nc < 0 or N <= nc:
                            continue
                        autumn[nr][nc] += 1
            
            if dead != -1:
                dead_trees = land[r][c][dead:]
                land[r][c] = land[r][c][:dead]
                a[r][c] += sum(map(lambda x: int(x / 2), dead_trees))
            
    for r in range(N):
        for c in range(N):
            for _ in range(autumn[r][c]):
                land[r][c].append(1)
            a[r][c] += A[r][c]

while K:
    K -=1
    seasons()

answer = 0
for r in range(N):
    for c in range(N):
        answer += len(land[r][c])
print(answer)