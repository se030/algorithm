import sys

N = int(sys.stdin.readline())

answer = -1
for q5 in range(N // 5, -1, -1):
    r = N - (5 * q5)
    if r % 3:
        continue
    answer = q5 + (r // 3)
    break

print(answer)
