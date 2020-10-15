import sys
from collections import deque 

s = input()
dq = deque(s)
n = int(input())
cnt = 0
for i in range(n):
    arr = sys.stdin.readline().split()
    if arr[0] == '2':
        if (arr[1] == '1' and cnt % 2 == 1) or (arr[1] == '2' and cnt % 2 == 0):
            dq.append(arr[2])
        else:
            dq.appendleft(arr[2])
    else:
        cnt += 1
if cnt%2==0:
    print(''.join(dq))
else:
    print(''.join(dq)[::-1])
