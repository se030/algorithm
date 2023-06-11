import sys

n = int(sys.stdin.readline())

addr, bit_flag, mask = (
    None,
    [int("00000000", 2) for _ in range(4)],
    [int("11111111", 2) for _ in range(4)],
)
for _ in range(n):
    cur = list(map(int, sys.stdin.readline().split(".")))
    if not addr:
        addr = cur[:]

    for i in range(3, -1, -1):
        a, b, c = addr[i], bit_flag[i], cur[i]

        if c != (a & c):  # 네트워크 주소 변화
            for j in range(7, -1, -1):  # 높은 비트부터 어디까지 공통인지
                if (a & (1 << j)) != (c & (1 << j)) or (
                    not (c & (1 << j)) and (b & (1 << j))
                ):
                    mask[i] = int("1" * (8 - j - 1) + "0" * (j + 1), 2)
                    break
            for j in range(i + 1, 4):
                addr[j] = 0
                mask[j] = 0

        addr[i] &= c  # 하나라도 0인 비트 토글
        bit_flag[i] |= c  # 하나라도 1인 비트 기록

print(".".join(list(map(str, addr))))
print(".".join(list(map(str, mask))))
