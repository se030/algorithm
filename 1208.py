import sys

N, S = map(int, sys.stdin.readline().split(" "))
A = list(map(int, sys.stdin.readline().split(" ")))

pivot = int(N / 2)
f, s = 1 << pivot, 1 << (N - pivot)  # half 요소로 만들어지는 조합
first, second = [0 for _ in range(f)], [0 for _ in range(s)]

for i in range(f):
    for j in range(pivot):
        if i & (1 << j):
            first[i] += A[j]
for i in range(s):
    for j in range(pivot, N):
        if i & (1 << (j - pivot)):
            second[i] += A[j]

first.sort()
second.sort()
answer, fp, sp = 0, 0, s - 1
while fp < f and 0 <= sp:
    cur = first[fp] + second[sp]
    if cur < S:
        fp += 1
    elif S < cur:
        sp -= 1
    else:
        fcount, scount = 1, 1

        while fp + 1 < f and first[fp] == first[fp + 1]:
            fp += 1
            fcount += 1
        while 0 <= sp - 1 and second[sp] == second[sp - 1]:
            sp -= 1
            scount += 1

        answer += fcount * scount
        fp += 1
        sp -= 1

print(answer if S != 0 else answer - 1)
