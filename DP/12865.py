import sys

N, K = map(int, sys.stdin.readline().strip().split(' '))

# N번째 물품까지-무게 K인 경우 최대 가치
dp = [[0 for _ in range(100001)] for _ in range(101)]
stuffs = []

for i in range(1, N + 1):
    W, V = map(int, sys.stdin.readline().strip().split(' '))
    dp[i][W] = V
    stuffs.append([W, V])

for idx, [w, v] in enumerate(stuffs):
    idx += 1
    for i in range(K + 1):
        dp[idx][i] = dp[idx - 1][i]
        if 0 <= i - w:
            dp[idx][i] = max(dp[idx][i], dp[idx - 1][i - w] + v)

print(dp[N][K])