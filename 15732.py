import sys

N, K, D = map(int, sys.stdin.readline().split(" "))
A, B, C = [0 for _ in range(K)], [0 for _ in range(K)], [0 for _ in range(K)]

for i in range(K):
    A[i], B[i], C[i] = map(int, sys.stdin.readline().split(" "))

lo, hi = 1, N
while lo <= hi:
    mid, dotori = int((lo + hi) / 2), 0
    for i in range(K):
        if mid < A[i]:
            continue
        dotori += int((min(B[i], mid) - A[i]) / C[i]) + 1

    if dotori < D:
        lo = mid + 1  # 마지막 도토리
    else:
        hi = mid - 1
print(lo)
