import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split(" ")))
A.sort()

answer = 0
for i in range(N - 2):
    lo = i + 1
    hi = N - 1

    while lo < hi:
        low, high = A[lo], A[hi]
        cur = A[i] + low + high

        if cur == 0:
            if low == high:
                cnt = hi - lo
                answer += int((cnt * (cnt + 1)) / 2)
                lo = hi
            else:
                cnt_lo, cnt_hi = 0, 0
                while A[lo] == low:
                    cnt_lo += 1
                    lo += 1
                while A[hi] == high:
                    cnt_hi += 1
                    hi -= 1
                answer += cnt_lo * cnt_hi

        elif cur < 0:
            while A[lo] == low:
                lo += 1
        else:
            while A[hi] == high:
                hi -= 1

print(answer)
