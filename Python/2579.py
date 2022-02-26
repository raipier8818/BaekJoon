import sys
sys.setrecursionlimit(10**8)

n = int(sys.stdin.readline())
stair = []
for i in range(n):
    stair.append(int(sys.stdin.readline()))

dp = [0 for _ in range(n)]
dp[0] = stair[0]

for i in range(n):
    if i == 1:
        dp[i] = max(dp[i-1] + stair[i],stair[i] + stair[i-1])

    if i == 2:
        dp[i] = max(dp[i-2] + stair[i], stair[i-1] + stair[i])

    if i > 2:
        dp[i] = max(stair[i] + dp[i-2], stair[i] + stair[i-1] + dp[i-3])

print(dp[n-1])