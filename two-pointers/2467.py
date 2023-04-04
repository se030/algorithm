import sys

N = int(sys.stdin.readline())
sol = list(map(int, sys.stdin.readline().split(' ')))

start, end, ans, answer = 0, N-1, 3000000000, None

while start != end:
    res = sol[start] + sol[end]
    
    if abs(res) < ans:
        ans = abs(res)
        answer = [sol[start], sol[end]]
    
    if res < 0:
        start += 1
    else:
        end -= 1
    
print(f'{answer[0]} {answer[1]}')