n = int(input())
arr = list(map(int,input().split()))

dp = [1 for _ in range(n)]

m = arr[0]
for i in range(0,n):
    for j in range(i-1,-1,-1):
        if arr[i] < arr[j]:
            dp[i] = dp[j] + 1
            break
        else:
            m = arr[i]


print(dp[-1])