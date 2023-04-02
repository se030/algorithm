import sys

answer, start, milk = 0, [None, None], []

N, M, H = map(int, sys.stdin.readline().strip().split())
for i in range(N):
    for j in range(N):
        x = int(sys.stdin.read(2).strip())
        if x == 1:
            start = [i, j]
        elif x == 2:
            milk.append([i, j])

def cost(start, end):
    return abs(start[0] - end[0]) + abs(start[1] - end[1])

range_milk = range(len(milk))
visited = [False for _ in range_milk]

def dfs(cur, h, count):
    global answer, range_milk, visited

    if (cost(cur, start) <= h):
        answer = max(answer, count) # 집으로 돌아갈 수 있는 경우
    
    if answer == len(milk):
        return
    
    for idx in range_milk:
        if visited[idx]:
            continue # 현재 탐색에서 이미 마신 우유
        
        visited[idx] = True
        c = cost(cur, milk[idx])
        if c <= h:
            dfs(milk[idx], h - c + H, count + 1)
        visited[idx] = False

dfs(start, M, 0)
print(answer)