n = int(input())
maze = list(map(int,input().split()))

dp = [9999 for _ in range(n)]
dp[0] = 0
for i in range(n):
    for j in range(i+1,i+maze[i]+1):
        if j < n-1:
            dp[j] = min(dp[i] + 1, dp[j])
        else:
            dp[n-1] = min(dp[i] + 1, dp[n-1])
            break

if dp[-1] == 9999:
    print(-1)
else:
    print(dp[-1])