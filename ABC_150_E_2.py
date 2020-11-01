import sys
r=sys.stdin.readline
N=int(r())
C=list(map(int,r().split()))
C.sort()
ans=0
MOD=10**9+7
for i in range(N):
    tmp=0
    l=i
    r=N-i-1
    tmp+=(pow(2,r,MOD))
    if r!=0: tmp+=r*pow(2,r-1,MOD)
    tmp*=pow(2,l,MOD)
    tmp*=C[i]
    ans+=tmp
print((ans*pow(2,N,MOD))%MOD)