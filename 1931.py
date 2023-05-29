import sys
from heapq import heapify, heappop

N = int(sys.stdin.readline())

meetings = []
for _ in range(N):
    start, end = map(int, sys.stdin.readline().split(" "))
    meetings.append([end, start])
heapify(meetings)

currentEnd, count = 0, 0
while meetings:
    end, start = heappop(meetings)
    if currentEnd <= start:
        count += 1
        currentEnd = end

print(count)
