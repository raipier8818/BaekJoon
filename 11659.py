import sys
input = sys.stdin.readline()
n, m = map(int,input.split())

arr = list(map(int,sys.stdin.readline().split()))
dp = [0 for _ in range(n)]
dp[0] = arr[0]
for j in range(1,n):
    dp[j] = dp[j-1] + arr[j]
dp.insert(0,0)

for i in range(m):
    a, b = map(int,sys.stdin.readline().split())

    print(dp[b]-dp[a-1])