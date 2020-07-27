test = int(input())

for i in range(test):
    a, b = map(int,input().split())
    num = 1
    for k in range(1,b+1):
        num *= k
    for j in range(1,a+1):
        num //= j
    for l in range(1, b-a+1):
        num //= l

    print(num)

