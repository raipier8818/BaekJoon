n = int(input())

work = []

dp = []
for i in range(n):
    work.append(list(map(int,input().split())))
    dp.append(0)
#
#
# for j in range(n-1, -1, -1):
#     if j + work[j][0] <= n:
#         dp[j] = work[j][1]

ans = -999999999
def f(day,pay):
    global ans
    if day == n:
        ans = max(ans,pay)
        return
    if day > n:
        return

    f(day + 1, pay)
    f(day + work[day][0], pay + work[day][1])

f(0,0)
print(ans)