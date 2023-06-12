import sys
from heapq import heapify, heappop, heappush

N = int(sys.stdin.readline())

cards = []
for i in range(N):
    cards.append(int(sys.stdin.readline()))
heapify(cards)

answer = 0
while 1 < len(cards):
    first, second = heappop(cards), heappop(cards)
    answer += first + second
    heappush(cards, first + second)

print(answer)
