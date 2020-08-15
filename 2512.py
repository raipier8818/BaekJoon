n = int(input())
arr = list(map(int,input().split()))

m = int(input())

mid = m // n
cost = 0
if sum(arr) <= m:
    print(max(arr))
    
else:
    while True:
        for i in range(n):
            if arr[i] < mid:
                cost += arr[i]
            else:
                cost += mid

        if cost > m:
            break

        elif cost < m:
            mid += 1
            cost = 0



    print(mid-1)