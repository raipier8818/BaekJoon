n = int(input())

stack = 0

for i in range(1,n+1):
    if i*(i+1)//2 > n:
        break
    a = n - i*(i+1)//2
    if a % i == 0:
        stack += 1

print(stack)