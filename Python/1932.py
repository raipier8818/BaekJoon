import sys
sys.setrecursionlimit(10**8)

n = int(input())

tri = []

visit = []
for i in range(n):
    row = list(map(int,input().split()))

    tri.append(row)
    visit.append([0 for _ in range(-1,i)])


for i in range(n-1,-1,-1):
    for j in range(i+1):
        if i != n-1:
            visit[i][j] = max(visit[i+1][j] + tri[i][j], visit[i+1][j+1] + tri[i][j])

        if i == n - 1:
            visit[i][j] = tri[i][j]

print(visit[0][0])