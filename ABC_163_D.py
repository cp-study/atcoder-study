n, k = map(int, input().split())
mod = 1000000007
ans = 0
for i in range(k, n+2):
  minSum = (i*(i-1))//2
  maxSum = (i*(2*n-i+1))//2
  ans += maxSum - minSum + 1
  ans %= mod
print(ans)
