import sys

n, m = int(input().split())

arr = []
for i in range(n):
    row = list(input())
    arr.append(row)

q = [[0,0,1]]

minnum = sys.maxsize
count = 0

dx = [1,-1,0,0]
dy = [0,0,1,-1]


while (len(q) > 0):
    cur = q.pop(0)
    x = cur[0]
    y = cur[1]
    w = cur[2]


    if cur[0] == m-1 and cur[1] == n-1:
        minnum = min(minnum,count)

    for i in range(4):
        X = x + dx[i]
        Y = y + dy[i]

        if 0 <= X < m and 0 <= Y < n:
