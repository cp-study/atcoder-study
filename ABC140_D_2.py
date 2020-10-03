import sys
r=sys.stdin.readline
N,K=map(int,r().split())
S=r().strip()
def HappyCnt(S):
    cnt=0
    if len(S)==1:
        return cnt
    for i in range(1,len(S)):
        if S[i-1]==S[i]:
            cnt+=1
    return cnt
cnt=HappyCnt(S)
LR=list(S).count("LR")
RL=list(S).count("RL")
print(min(N-1,cnt+2*K))