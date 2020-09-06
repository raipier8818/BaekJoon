n = int(input())

time = list(map(int,input().split()))
time.sort()
dp = [ 0 for _ in range(n)]
dp[0] = time[0]
for i in range(1,n):
    dp[i] = dp[i-1] + time[i]

print(sum(dp))