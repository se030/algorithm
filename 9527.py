import sys

A, B = map(int, sys.stdin.readline().split(" "))
ones = [0 for _ in range(60)]
for i in range(1, 60):
    ones[i] = 2 ** (i - 1) + 2 * ones[i - 1]


def count(num):
    binary = bin(num).replace("0b", "")
    ret, length = 0, len(binary)
    for i in range(length):
        if int(binary[i]):
            l = length - i - 1
            num -= 2**l
            ret += ones[l] + (num + 1)  # 누적 1 + 맨 앞자리 1의 개수
    return ret


print(count(B) - count(A - 1))
