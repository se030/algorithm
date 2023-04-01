import sys

code = sys.stdin.readline().strip()

length = len(code)
dp = [0 for _ in range(length)] # idx i번째까지 나올 수 있는 해석 개수

if (code[0] == '0'):
    print(0)

else:
    dp[0] = 1;
    if (int(code[:2]) in range(10, 27)):
        dp[1] = 1;

    for i in range(1, length):
        if (int(code[i]) in range(1, 10)):
            dp[i] += dp[i - 1]
            dp[i] %= 1000000
        if (1 < i and int(code[i - 1 : i + 1]) in range(10, 27)):
            dp[i] += dp[i - 2]
            dp[i] %= 1000000

    print(dp[length - 1])