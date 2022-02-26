n,m = map(int,input().split())

tree = list(map(int,input().split()))
start = max(tree)
end = 0

while start >= end:
    mid = (start + end) // 2
    log = 0
    for i in range(n):
        if tree[i] > mid:
            log += tree[i] - mid

    if log >= m:
        end = mid + 1
    else:
        start = mid - 1

print(start)