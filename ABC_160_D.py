import sys
from collections import deque
r=sys.stdin.readline
N,X,Y=map(int,r().split())
res=[0]*N
G=[[] for _ in range(N+1)]
for i in range(1,N):
    G[i].append(i+1)
    G[i+1].append(i)
G[X].append(Y)
G[Y].append(X)

def bfs(start):
    q=deque([(start,0)])
    visited=[False]*(N+1)
    visited[start]=True
    cnt=0
    while q:
        cur,d=q.popleft()
        if d!=0:
            res[d]+=1
        for v in G[cur]:
            if not visited[v]:
                visited[v]=True
                q.append((v,d+1))
    return cnt
for i in range(1,N+1):
    bfs(i)
for j in range(1,N):    
    print(res[j]//2)