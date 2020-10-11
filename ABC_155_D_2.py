from bisect import bisect
import sys
r=sys.stdin.readline
n,k=map(int,r().split())
a=list(map(int,r().split()))
a.sort()
i=bisect(a,0)
a,b=a[i:],a[i-1::-1]
#a는 양수 b는 0을 포함한 음의 정수
n,m=len(a),len(b)
ok=10**18
ng=-ok
while ok-ng>1:
    x=(ok+ng)//2
    s=0
    if x>=0:
        i=n
        #i에 a의 길이
        for y in a:#양수 * 양수의 경우
            while i and a[i-1]*y > x:   #i값이 양수 즉 a배열에 접근할 수 있고
                i-=1                    #x값보다 큰 값이면.. 
            s+=i
            if y*y<=x:#자신을 두번곱하는경우 제외
                s-=1
        i=m
        for y in b:#음수 * 음수의 경우
            while i and b[i-1]*y > x:
                i-=1
            s+=i
            if y*y <= x:#자신을 두번곱하는경우 제외
                s-=1
        s=s//2+n*m
    else:
        i=m
        #i에 b의 길이
        for y in a:#음수 * 양수의 경우
            while i and b[i-1]*y <= x:
                i-=1
            s+=m-i
    if s>=k:
        ok=x
    else:
        ng=x
print(ok)