import sys
r=sys.stdin.readline
N=int(r())
C=list(map(int,r().split()))
C.sort()
ans=0
for i in range(N):
    ans+=((N-i)+1)*C[i]
MOD=10**9+7
ans*=pow(2,2*N-2,MOD)
ans%=MOD
print(ans)