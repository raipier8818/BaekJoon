import sys
sys.setrecursionlimit(10**6)

n, m, v = map(int,input().split())


node = []
for j in range(n):
    node.append([])

for i in range(m):
    a, b = map(int,input().split())
    if b not in node[a-1]:
        node[a-1].append(b)
    for k in range(len(node[a-1])):
        if a not in node[node[a-1][k]-1]:
            node[node[a-1][k]-1].append(a)

for ll in range(len(node)):
    node[ll].sort()

visited_dfs = []
def dfs(first):
    visited_dfs.append(first)
    print(first, end=" ")
    for i in range(len(node[first-1])):
        if node[first-1][i] not in visited_dfs:
            dfs(node[first-1][i])

dfs(v)
print()
index = 0
visited_bfs = [v]
def bfs(first, index):
    for i in range(len(node[first-1])):
        if node[first-1][i] not in visited_bfs:
            visited_bfs.append(node[first-1][i])
    index += 1
    if index < len(visited_bfs):
        bfs(visited_bfs[index],index)

bfs(v,index)
for nn in range(len(visited_bfs)):
    print(visited_bfs[nn], end=" ")

print()