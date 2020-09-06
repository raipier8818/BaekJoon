import sys
n = int(sys.stdin.readline())
arr = list(map(int,sys.stdin.readline().split()))
arr.sort()

m = int(sys.stdin.readline())
kind = list(map(int,sys.stdin.readline().split()))

def find_lower(start,end,target):
    while start < end:
        mid = (start+end)//2

        if arr[mid] >= target:
            end = mid-1
        elif arr[mid] < target:
            start = mid+1

    return end


def find_upper(start, end, target):
    while start < end:
        mid = (start + end) // 2

        if arr[mid] > target:
            end = mid - 1
        elif arr[mid] <= target:
            start = mid + 1

    return end

for i in kind:
    lower = find_lower(0,n,i)
    upper = find_upper(0,n,i)

    if upper == n - 1 and arr[n-1] == i:
        upper += 1

    print(upper - lower, end=" ")