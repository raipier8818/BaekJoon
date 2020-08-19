n, k = map(int,input().split())

arr = []
for i in range(n):
    arr.append(int(input()))

start = 1
end = max(arr)

while start <= end:
    mid = (start + end) // 2
    count = 0
    for i in arr:
        count += i // mid

    if count < k:
        end = mid - 1
    else:
        start = mid + 1

print(end)