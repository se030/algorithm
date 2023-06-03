import sys

N = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split(" ")))
dp = A[:]

for i in range(N - 1, -1, -1):
    for j in range(i + 1, N):
        if A[i] < A[j]:
            dp[i] = max(dp[i], dp[j] + A[i])

print(max(dp))
