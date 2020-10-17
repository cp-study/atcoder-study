import sys            
def main():
    r=sys.stdin.readline
    R,C,K=map(int,r().split())
    dp=[[[0]*(C+1) for _ in range(R+1)] for _ in range(4)]
    tb=[[0]*(C+1) for _ in range(R+1)]
    for _ in range(K):
        row,col,item=list(map(int,r().split()))
        tb[row][col]=item

    for i in range(1,R+1):
        for j in range(1,C+1):
            dp[0][i][j]=max(dp[0][i][j-1],dp[0][i-1][j],dp[1][i-1][j],dp[2][i-1][j],dp[3][i-1][j])
            if tb[i][j]>0:      #item이 있을때
                dp[1][i][j]=max(dp[0][i][j-1],dp[0][i-1][j],dp[1][i-1][j],dp[2][i-1][j],dp[3][i-1][j])+tb[i][j]
                dp[1][i][j]=max(dp[1][i][j],dp[1][i][j-1])
                dp[2][i][j]=max(dp[1][i][j-1]+tb[i][j],dp[2][i][j-1])
                dp[3][i][j]=max(dp[2][i][j-1]+tb[i][j],dp[3][i][j-1])
            else:
                dp[1][i][j]=dp[1][i][j-1]
                dp[2][i][j]=dp[2][i][j-1]
                dp[3][i][j]=dp[3][i][j-1]
    print(max(dp[0][R][C],dp[1][R][C],dp[2][R][C],dp[3][R][C]))
main()
