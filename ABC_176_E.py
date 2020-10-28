import sys
from collections import deque
import math
import copy
input = sys.stdin.readline
 
H,W,M = map(int,input().split())
row = [0 for _ in range(H+1)]
col = [0 for _ in range(W+1)]
stack = []
 
for i in range(M):
    h,w = map(int,input().split())
    row[h] +=1
    col[w] +=1
    stack.append((h,w))
m_row = max(row)
row_stack = []
for i in range(len(row)):
    if row[i] == m_row:
        row_stack.append(i)
m_col = max(col)
col_stack = []
for i in range(len(col)):
    if col[i] == m_col:
        col_stack.append(i)
ans = m_row + m_col
#print(row_stack)
#print(col_stack)
check = set(stack)
for i in row_stack:
    for j in col_stack:
        if (i,j) not in check:
            print(ans)
            exit()
print(ans-1)
