import sys
from heapq import heappush, heappop

N, K = map(int, sys.stdin.readline().split(" "))
height = list(map(int, sys.stdin.readline().split(" ")))

diff = []
for i in range(1, N):
    heappush(diff, -(height[i] - height[i - 1]))
for _ in range(K - 1):
    heappop(diff)

print(-1 * sum(diff))
