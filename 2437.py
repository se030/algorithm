import sys

N = int(sys.stdin.readline())
w = list(map(int, sys.stdin.readline().split(" ")))

w.sort()  # 가벼운 추부터 쌓으면서 불가능한 값 탐색
answer = 1  # 현재까지의 누적합 + 1
for weight in w:
    # 현재까지의 누적합 이하의 값은 모두 만들 수 있는 조합
    if answer < weight:  # anser < weight라면 answer 값은 만들 수 없음
        break
    answer += weight

print(answer)
