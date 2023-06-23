import sys
from collections import deque

S = int(sys.stdin.readline())

Q, visited = deque(), dict()
Q.append((1, 0))
visited[(1, 0)] = 0

while Q:
    cnt, clipboard = Q.popleft()
    if cnt == S:
        print(visited[(cnt, clipboard)])
        break

    if (cnt, cnt) not in visited.keys():
        Q.append((cnt, cnt))
        visited[(cnt, cnt)] = visited[(cnt, clipboard)] + 1

    if clipboard and (cnt + clipboard, clipboard) not in visited.keys():
        Q.append((cnt + clipboard, clipboard))
        visited[(cnt + clipboard, clipboard)] = visited[(cnt, clipboard)] + 1

    if (cnt - 1, clipboard) not in visited.keys():
        Q.append((cnt - 1, clipboard))
        visited[(cnt - 1, clipboard)] = visited[(cnt, clipboard)] + 1
