import sys,math
r=sys.stdin.readline
def gcd(a,b):
    a,b=max(a,b),min(a,b)
    while b>0:
        a,b=b,a%b
    return a
def lcm(arr):
    while len(arr)!=1:
        a=arr.pop()
        b=arr.pop()
        c=gcd(a,b)
        arr.insert(0,int(a*b/c))
    return arr[0]
def cnt2(num):
    cnt=0
    while num%2==0:
        num/=2
        cnt+=1
    return cnt
N,M=map(int,r().split())
seq=list(map(int,r().split()))
seq=list(set(seq))
tmp=cnt2(seq[0])
for num in seq:
    if tmp!=cnt2(num):
        print(0)
        exit(0)
T=lcm(list(map(lambda x: x//2,seq)))
if T>M:
    print(0)
    exit(0)
print(math.floor(M//T/2+0.5))



