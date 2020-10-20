N = int(input())
A = []

for i in range(N):
    x,y = map(int,input().split())
    A.append([x,y])
    
V = [0 for _ in range(N)]
V1 = [0 for _ in range(N)]

for i in range(N):
    V[i] = A[i][0] + A[i][1]
    V1[i] = A[i][0] - A[i][1]
    
V.sort()
V1.sort()

maximum = max(V[-1]-V[0],V1[-1]-V1[0])
print(maximum)
