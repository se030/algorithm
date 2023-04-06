def solution(queue1, queue2):
    sum1, sum2 = sum(queue1), sum(queue2)
    
    if (sum1 + sum2) % 2:
        return -1

    answer, idx1, idx2, length = 0, 0, 0, len(queue1)

    while True:
        if sum1 == sum2:
            return answer
        
        answer += 1
        
        if sum1 < sum2:
            num = queue2[idx2]
            idx2 += 1
            queue1.append(num)
            sum1 += num
            sum2 -= num
        else:
            num = queue1[idx1]
            idx1 += 1
            queue2.append(num)
            sum1 -= num
            sum2 += num

        if idx1 == 2 * length or idx2 == 2 * length:
            return -1

'''
풀면서 이게 맞나 했는데 자료구조 쓸 생각을 왜 안했는지 모르겠음 ...

from collections import deque

def solution(queue1, queue2):
    sum1, sum2 = sum(queue1), sum(queue2)
    
    if (sum1 + sum2) % 2:
        return -1

    answer, limit = 0, 4 * len(queue1)
    initialState = [sum1, sum2]
    queue1, queue2 = deque(queue1), deque(queue2)

    while True:
        if sum1 == sum2:
            return answer
        if answer == limit:
            return -1
        
        answer += 1
        
        if sum1 < sum2:
            num = queue2.popleft()
            queue1.append(num)
            sum1 += num
            sum2 -= num
        else:
            num = queue1.popleft()
            queue2.append(num)
            sum1 -= num
            sum2 += num
'''