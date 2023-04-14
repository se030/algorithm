import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split(' ')))

lis = [A[0]]
def search(num):
    global lis
    if lis[-1] < num:
        lis.append(num)
    else:
        lo, hi = 0, len(lis) - 1
        while lo < hi:
            mid = int((lo + hi) / 2)
            if lis[mid] < num:
                lo = mid + 1
            else:
                hi = mid
        lis[hi] = num

for idx in range(1, N):
    search(A[idx])
    
print(len(lis))