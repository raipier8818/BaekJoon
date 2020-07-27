num = int(input())

a = list(map(int,input().split()))
b = list(map(int,input().split()))

b_ = []

for i in range(num):
    b_.append(b[i])

a.sort()
b_.sort(reverse= True)

add = 0

for k in range(num):
    add += a[k]*b_[k]

print(add)