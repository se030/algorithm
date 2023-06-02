import sys

S = sys.stdin.readline()

flag = int(S[0])
zero, one = 1 if not flag else 0, 1 if flag else 0
for s in S[:-1]:
    n = int(s)
    if n and not flag:
        one += 1
        flag = n
    elif not n and flag:
        zero += 1
        flag = n

print(min(zero, one))
