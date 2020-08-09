import sys
sys.setrecursionlimit(10**8)

t = int(input())

def count(n,m):
    farm[n][m] = 0
    if farm[n-1][m] == 1:
        count(n-1,m)
    if farm[n][m+1] == 1:
        count(n,m+1)
    if farm[n][m-1] == 1:
        count(n,m-1)
    if farm[n+1][m] == 1:
        count(n+1,m)
    return

for i in range(t):
    m, n, k = map(int,input().split())
    farm = []
    for a in range(n+2):
        farm_row = []
        for b in range(m+2):
            farm_row.append(0)
        farm.append(farm_row)



    for j in range(k):
        x, y = map(int, input().split())
        farm[y+1][x+1] = 1

    c = 0
    for A in range(1,n+1):
        for B in range(1,m+1):
            if farm[A][B] == 1:
                count(A,B)
                c += 1

    print(c)