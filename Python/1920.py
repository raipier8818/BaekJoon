import sys
sys.setrecursionlimit(10**8)

def find(arr,start,end,f):
    if start > end:
        print(0)
        return
    mid = (start+end)//2
    if arr[mid] > f:
        find(arr,start,mid-1,f)
    elif arr[mid] < f:
        find(arr,mid+1,end,f)
    else:
        print(1)
        return



n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
arr = sorted(arr)
m = int(sys.stdin.readline())
num = list(map(int,sys.stdin.readline().split()))


for i in range(m):
    find(arr,0,n-1,num[i])