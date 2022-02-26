import sys

n = int(input())

arr = ['1']

def check(l):
    mid = l//2
    for i in range(1,mid+1):
        if arr[l-i:l] == arr[l-i*2:l-i]:
            return 0
    
    return 1

def find(l):
    if l == n:
        print("".join(arr))
        sys.exit()
    
    for i in range(1,4):
        arr.append(str(i))
        if check(l+1):
            find(l+1)
        arr.pop()


find(1)