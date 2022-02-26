a, b = map(int,input().split())

index_a = 0
while True:
    if a <= index_a * (index_a+1)//2:
        sub_a = index_a * (index_a + 1) // 2 - a
        break
    index_a += 1

index_b = 0
while True:
    if b <= index_b * (index_b + 1) // 2:
        sub_b = index_b * (index_b + 1) // 2 - b
        break
    index_b += 1


sum = 0

if index_a != index_b:
    for i in range(index_a+1, index_b):
        sum += i*i

    sum += index_a * (sub_a + 1)
    sum += index_b * (index_b - sub_b)

else:
    sum += index_a*(sub_a - sub_b+1)

print(sum)