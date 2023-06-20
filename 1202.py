import sys
from heapq import heapify, heappop, heappush

N, K = map(int, sys.stdin.readline().split(" "))
jewels, C = [], []
for _ in range(N):
    M, V = map(int, sys.stdin.readline().split(" "))
    heappush(jewels, [M, V])
for _ in range(K):
    heappush(C, int(sys.stdin.readline()))

answer, candidates = 0, []
while C:
    c = heappop(C)
    while jewels and jewels[0][0] <= c:
        M, V = heappop(jewels)
        heappush(candidates, -V)
    if candidates:
        answer -= heappop(candidates)
print(answer)
