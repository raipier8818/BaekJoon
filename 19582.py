import sys
sys.setrecursionlimit(10**8)
n = int(sys.stdin.readline())


money = 0
count = 0

arr = []
for i in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))

max = 0
def dfs(index, count, money):
    global max
    if index == n:
        if count > max:
            max = count
        return

    if money <= arr[index][0]:
        dfs(index+1,count+1,money+arr[index][1])

    dfs(index+1,count,money)
dfs(0,0,0)


if max >= n-1:
    print('Kkeo-eok')
else:
    print('Zzz')