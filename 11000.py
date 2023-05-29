import sys
from heapq import heapify, heappop, heappush, heappushpop

N = int(sys.stdin.readline())

lectures, ongoing, answer = [], [], 0
for _ in range(N):
    s, t = map(int, sys.stdin.readline().split(" "))
    lectures.append([s, t])
heapify(lectures)

while lectures:
    s, t = heappop(lectures)
    end = heappop(ongoing) if ongoing else 1000000001
    if end <= s:
        heappush(ongoing, t)
    else:
        answer += 1
        heappush(ongoing, t)
        heappush(ongoing, end)

print(answer)
