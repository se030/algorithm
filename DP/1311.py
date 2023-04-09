import sys

N = int(sys.stdin.readline())
cost = []
for _ in range(N):
    cost.append(list(map(int, sys.stdin.readline().split(' '))))

MAX_COST, COMPLETE = 500000, (1 << N) - 1
dp = [MAX_COST for _ in range(COMPLETE + 1)]

def works_to_do(mask):
    res, cnt, idx = list(range(N)), 0, 0
    while mask:
        if mask & 1:
            cnt += 1
            res.remove(idx)
        mask >>= 1
        idx += 1
    return [res, cnt]

dp[0] = 0
for mask in range(COMPLETE):
    works, n = works_to_do(mask)
    for work in works:
        next = mask | (1 << work)
        dp[next] = min(dp[next], dp[mask] + cost[n][work])

print(dp[COMPLETE])