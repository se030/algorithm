import sys

arr, start, end, answer = [], 0, 0, 3000000000

N, M = map(int, sys.stdin.readline().split(' '))
for _ in range(N):
    arr.append(int(sys.stdin.readline()))

arr.sort()

while start <= end and start < N - 1:
    diff = arr[end] - arr[start]
    
    if diff < M:
        end += 1
    else:
        answer = min(answer, diff)
        start += 1
    
    if end == N:
        break

print(answer)