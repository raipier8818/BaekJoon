# from itertools import combinations
#
# while True:
#     l = list(map(int,input().split()))
#     k = l[0]
#     s = l[1:]
#
#     if k == 0:
#         break
#     answer = list(combinations(s,6))
#     answer.sort()
#     for i in range(len(answer)):
#         p = list(answer[i])
#         for j in range(len(p)):
#             print(p[j],end=" ")
#         print()
#
#     print()


def dfs(start, depth):
    global combination
    if depth == 6:
        for j in range(6):
            print(combination[j],end=" ")
        print()
        return

    for i in range(start, len(s)):
        combination[depth] = s[i]
        dfs(i+1, depth+1)

k = 0
s = []
global combination
while True:
    l = list(map(int,input().split()))
    k = l[0]
    s = l[1:]
    if k == 0:
        break

    combination = []
    for i in range(6):
        combination.append(0)
    dfs(0,0)
    print()