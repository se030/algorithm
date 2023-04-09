import sys

N = int(sys.stdin.readline())

num = 665
for _ in range(N):
    num += 1
    while '666' not in str(num):
        num += 1

print(num)