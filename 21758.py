import sys

N = int(sys.stdin.readline())
honey = list(map(int, sys.stdin.readline().split(" ")))

arr = [None for _ in range(N)]
for idx, el in enumerate(honey):
    arr[idx] = (arr[idx - 1] if 0 < idx else 0) + el

answer = 0
for idx in range(1, N - 1):  # 1 ~ N - 2
    # idx
    sum1 = arr[idx] - arr[0] + arr[N - 2] - arr[idx - 1]
    # 0
    sum2 = arr[N - 2] - honey[idx] + arr[idx - 1]
    # N - 1
    sum3 = 2 * arr[N - 1] - (arr[0] + honey[idx] + arr[idx])

    answer = max(answer, sum1, sum2, sum3)

print(answer)
