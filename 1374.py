import sys
from heapq import heappush, heappop

N = int(sys.stdin.readline())
lecture = []
for _ in range(N):
    _, start, end = map(int, sys.stdin.readline().split(" "))
    lecture.append([start, end])

lecture.sort(key=lambda el: el[0])
classroom, freed = 0, []
for l in lecture:
    start, end = l
    earliest = heappop(freed) if len(freed) else 1000000001
    if start < earliest:
        classroom += 1
        heappush(freed, earliest)
    heappush(freed, end)

print(classroom)
