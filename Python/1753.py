# import sys
#
# v, e = map(int,sys.stdin.readline().split())
# k = int(sys.stdin.readline())
#
# node = [[] for _ in range(v)]
#
# for i in range(e):
#     u, v, w = map(int,sys.stdin.readline().split())
#
#     if v not in node[u-1]:
#         node[u-1].append([v,w])
#     # if u not in node[v-1]:
#     #     node[v-1].append([u,w])
#
#
#
# heap = []
# visit = [-1 for _ in range(-1,v+1)]
#
# heap.append([k-1,0])
#
# while len(heap) > 0:
#     heap = sorted(heap,key=lambda x:x[1])
#     next = heap.pop(0)
#     n = next[0]
#     w = next[1]
#     if visit[n] == -1:
#         visit[n] = w
#         for j in range(len(node[n-1])):
#             heap.append([node[n-1][j][0],node[n-1][j][1] + w])
#     else:
#         continue
#
# visit.pop(0)
# for k in visit:
#     if k == -1:
#         print('INF')
#     else:
#         print(k-1)
#
# import sys
# import heapq
#
# v,e = map(int,sys.stdin.readline().split())
# dp = [sys.maxsize] * v
#
# k = int(sys.stdin.readline())
# dp[k] = 0
#
# node = [[]for _ in range(v)]
# for i in range(e):
#     u,v,w = map(int,sys.stdin.readline().split())
#     u -= 1
#     v -= 1
#     if v not in node[u]:
#         node[u].append([v,w])
#
# heap = []
# heapq.heappush(heap,(0,k-1))
#
# while len(heap) > 0:
#     a,b = heapq.heappop(heap)
#
#     if dp[b] < a:
#         continue
#
#     for w, next in node[b]:
#         next_w = w + a
#         if next_w < dp[next]:
#             dp[next] = next_w
#             heapq.heappush(heap,(next_w,next))
#
#
#
# for k in range(v):
#     print('INF' if dp[i] == sys.maxsize else dp[i])

import sys
import heapq

v,e = map(int,sys.stdin.readline().split())
visit = [sys.maxsize]*v

k = int(sys.stdin.readline())
node = [[]for _ in range(v)]

for i in range(e):
    u,v,w = map(int,sys.stdin.readline().split())
    u -= 1
    v -= 1
    node[u].append([v,w])

heap = []
def f(k):
    visit[k-1] = 0
    heapq.heappush(heap,[0,k-1])
    while heap:
        a,b = heapq.heappop(heap)

        if visit[b] < a:
            continue

        for next_node, w in node[b]:
            if w + a < visit[next_node]:
                visit[next_node] = w + a
                heapq.heappush(heap,[w+a,next_node])

f(k)
for k in range(len(visit)):
    if visit[k] == sys.maxsize:
        print('INF')
    else:
        print(visit[k])

