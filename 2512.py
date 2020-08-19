n = int(input())
govern = list(map(int,input().split()))

budget = int(input())

start = 0
end = max(govern)

while start <= end:
    mid = (start + end) // 2

    b = 0
    for i in govern:
        if i < mid:
            b += i
        else:
            b += mid

    if b <= budget:
        start = mid + 1
    else:
        end = mid - 1

print(end)