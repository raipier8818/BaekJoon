def f(num):
    l = int(num**0.5)
    for i in range(2,l+1):
        if num % i == 0:
            return 0
    return 1

m, n = map(int,input().split())

for i in range(m,n+1):
    c = f(i)
    if c == 1:
        print(i)