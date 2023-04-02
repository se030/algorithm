import sys

pos = []

N, C = map(int, sys.stdin.readline().strip().split(' '))
for _ in range(N):
    x = int(sys.stdin.readline())
    pos.append(x)
    
pos.sort()
lo, hi = 0, pos[N - 1]

def count(n):
    global pos
    res, dist = 1, 0
    for idx in range(1, N):
        dist += pos[idx] - pos[idx - 1]
        if (n <= dist):
            res += 1
            dist = 0
    return res

while (lo <= hi):
    mid = int((lo + hi) / 2)
    
    if (C <= count(mid)):
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)