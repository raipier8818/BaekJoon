l = int(input())

num = list(map(int,input().split()))
num.sort()

n = int(input())

if n not in num:
    if 1 not in num:
        num.insert(0, 0)
    index = 0

    while index < len(num)-2:
        if num[index] < n and num[index+1] > n:
            break
        index += 1

    sum = 0
    for i in range(num[index]+1,n+1):
        sum += num[index+1] - n
    print(sum-1)

else:
    print(0)