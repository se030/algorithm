import sys

N, M = map(int, sys.stdin.readline().split(" "))
A = list(map(int, sys.stdin.readline().split(" ")))

# 0 ~ i 누적합 % M 값이 remainder 인덱스
# 같은 나머지 가진 누적합끼리의 조합은 나누어 떨어지는 구간을 만듬
remainder = [[] for _ in range(M)]

remainder[A[0] % M].append(0)
for i in range(1, N):
    A[i] += A[i - 1] % M
    remainder[A[i] % M].append(i)

answer = len(remainder[0])
for r in remainder:
    length = len(r)
    if length:
        answer += int(length * (length - 1) / 2)
print(answer)
