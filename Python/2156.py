import sys
n = int(sys.stdin.readline())

wine = []
for i in range(n):
    wine.append(int(input()))

dp = [0 for _ in range(n+1)]

def find(index,count,stair):
    if index == n:
        dp[n] = max(dp[n], count)
        return

    if stair == 3:
        find(index + 2, count + wine[index], 1)
    else:
        find(index + 1, count + wine[index], stair + 1)

find(0,0,1)

print(dp[n])