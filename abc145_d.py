import sys
r=sys.stdin.readline
X,Y=map(int,r().split())
#a=X-2b, b=Y-2a
if 2*X-Y<0 or (2*X-Y)%3!=0 or 2*Y-X<0 or (2*Y-X)%3!=0:
    print(0)
    exit(0)   
a=(2*Y-X)//3
b=(2*X-Y)//3
MOD=10**9+7
#ex) ab, ba --> a+bCa
def pow(a,b):
    ans=1
    while b:
        if b&1:
            ans=(ans*a)%MOD
        a=(a**2)%MOD
        b=b//2
    return ans 
N=a+b
K=a
fac=[1 for _ in range(N+1)]
for i in range(2,N+1):
    fac[i]=(fac[i-1]*i)%MOD
A=fac[N]
B=(fac[N-K]*fac[K])%MOD
print((A%MOD)*pow(B,MOD-2)%MOD)

