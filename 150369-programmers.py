def solution(cap, n, deliveries, pickups):
    dist, deliver, pickup = 0, 0, 0
    for idx in range(n - 1, -1, -1):
        if deliveries[idx] or pickups[idx]:
            while deliver < deliveries[idx] or pickup < pickups[idx]: # 왕복이 필요한 경우
                dist += 2 * (idx + 1)
                deliver += cap # 여유 capacity
                pickup += cap
            deliver -= deliveries[idx]
            pickup -= pickups[idx]
    return dist