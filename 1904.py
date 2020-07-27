def combination(n,i):
    add = 1
    for i in range(1,n+1):
        

n = int(input())

m = n//2
sum = 0
for i in range(m):
    if i == 0:
        sum += 1
    sum += combination(n,i)