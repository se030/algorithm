import sys

dp = [-1 for _ in range(30)]
dp[0] = 0
dp[1] = 1


def factorial(n):
    if dp[n] == -1:
        dp[n] = n * factorial(n - 1)
    return dp[n]


T = int(sys.stdin.readline())
for _ in range(T):
    N, M = map(int, sys.stdin.readline().split(" "))
    if N == M:
        print(1)
        continue
    print(int(factorial(M) / (factorial(M - N) * factorial(N))))
