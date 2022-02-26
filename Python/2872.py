n = int(input())

num = []

for i in range(n):
    a = int(input())
    num.append(a)

index = n
for j in range(n-1,-1,-1):
    if num[j] == index:
        index -= 1

print(index)