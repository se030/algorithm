import sys

N = int(sys.stdin.readline())
D = list(map(int, sys.stdin.readline().split(" ")))

s, answer, minn, maxx = 0, 0, 0, 0
for d in D:
    s += 1 if d == 1 else -1
    answer = max(answer, abs(s - minn), abs(maxx - s))
    minn = min(minn, s)
    maxx = max(maxx, s)

print(answer)
