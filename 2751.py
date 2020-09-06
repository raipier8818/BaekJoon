def sort(n):
    if len(n) == 1:
        return n

    mid = len(n)//2
    g1 = n[:mid]
    g2 = n[mid:]
    sort(g1)
    sort(g2)


    idx = 0
    while len(g1) > 0 and len(g2) > 0:
        if g1[0] > g2[0]:
            p = g2.pop(0)
            n[idx] = p
            idx += 1

        elif g1[0] < g2[0]:
            p = g1.pop(0)
            n[idx] = p
            idx += 1
    while g1:
        n[idx] = g1.pop(0)
        idx += 1
    while g2:
        n[idx] = g2.pop(0)
        idx += 1

import sys
n = int(input())
arr = []
for i in range(n):
    num = int(input())
    arr.append(num)

sort(arr)

for i in arr:
    print(i)