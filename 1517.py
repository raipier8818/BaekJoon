import sys
sys.setrecursionlimit(10**8)
n = int(input())
arr = list(map(int,sys.stdin.readline().split()))
swap = 0

def mergesort(start,end):
    global swap
    if end - start == 1:
        return

    mid = (start+end)//2

    mergesort(start,mid)
    mergesort(mid,end)
    new = []
    i1, i2 = start, mid
    count = 0
    while i1 < mid and i2 < end:
        if arr[i1] > arr[i2]:
            new.append(arr[i2])
            i2 += 1
            count += 1
        else:
            new.append(arr[i1])
            i1 += 1
            swap += count

    while i1 < mid:
        new.append(arr[i1])
        i1 += 1
        swap += count
    while i2 < end:
        new.append(arr[i2])
        i2 += 1

    for i in range(len(new)):
        arr[start+i] = new[i]

mergesort(0,n)
print(swap)