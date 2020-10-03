import sys

n = int(input())
arr= list(map(int,sys.stdin.readline().split()))
arr = sorted(arr)
max_num = max(arr)
dp = [0 for i in range(max_num+1)]
for i in arr:
    j = i
    while j<=max_num:
        dp[j]+=1
        j+=i
ans = 0
for i in arr:
    if dp[i] == 1:
        ans+=1
print(ans)
