import sys

N, M = map(int, sys.stdin.readline().split(" "))
books = list(map(int, sys.stdin.readline().split(" ")))
books.sort()

p = len(books)
for idx, b in enumerate(books):
    if 0 < b:
        p = idx
        break

acc, dist = [], []
for b in books[:p]:
    if len(acc) == M:
        dist.append(abs(min(acc)))
        acc = []
    acc.append(b)
if acc:
    dist.append(abs(min(acc)))
    acc = []

for idx in range(len(books) - 1, p - 1, -1):
    b = books[idx]
    if len(acc) == M:
        dist.append(abs(max(acc)))
        acc = []
    acc.append(b)
if acc:
    dist.append(abs(max(acc)))

print(2 * sum(dist) - max(dist))
