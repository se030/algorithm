import sys

N = int(sys.stdin.readline())

schedule = []
dp = [0 for _ in range(N + 1)]
for i in range(1, N + 1):
    T, P = map(int, sys.stdin.readline().split(' '))
    
    dp[i] = max(dp[i - 1], dp[i])
    end = i + T - 1
    if end <= N:
        dp[end] = max(dp[end], dp[i - 1] + P) # 종료일까지는 새로운 상담 시작할 수 없음

print(dp[N])