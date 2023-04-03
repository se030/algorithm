import sys

cost = []

N = int(sys.stdin.readline())
for _ in range(N):
    cost_list = list(map(int, sys.stdin.readline().split(' ')))
    cost.append(cost_list)

MAX_COST = 10000000
answer = MAX_COST

# 첫번째 집이 r, g, b
for first in range(3):
    # N번째 집까지 고려, 현재 색깔이 ? 최소 비용
    dp = [[0 for _ in range(3)] for _ in range(1001)]
    dp[1] = [cost[0][i] if i == first else MAX_COST for i in range(3)]
    
    for idx, [r, g, b] in enumerate(cost[1:]):
        idx += 2
        dp[idx][0] = min(dp[idx - 1][1], dp[idx - 1][2]) + r
        dp[idx][1] = min(dp[idx - 1][0], dp[idx - 1][2]) + g
        dp[idx][2] = min(dp[idx - 1][0], dp[idx - 1][1]) + b
    
    min_cost = min(map(lambda x: x[1], filter(lambda x: x[0] != first, enumerate(dp[N]))))
    answer = min(answer, min_cost)

print(answer)