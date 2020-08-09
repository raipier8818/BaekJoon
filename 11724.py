import sys
sys.setrecursionlimit(10**8)

n, m = map(int,input().split())
node = [[]for _ in range(n)]

for i in range(m):
    a, b = map(int,sys.stdin.readline().split())
    a -= 1
    b -= 1

    node[a].append(b)
    node[b].append(a)



visit = list(0 for __ in range(n))

def find(num):
    visit[num] = 1
    for i in range(len(node[num])):
        if visit[node[num][i]] == 0:
            find(node[num][i])

count = 0
for j in range(n):
    if visit[j] == 0:
        find(j)
        count += 1

print(count)
