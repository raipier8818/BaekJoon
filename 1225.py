a, b = map(int,input().split())

arr_a = []
arr_b = []

while a!=0 or b!=0:
    num_a = a%10
    num_b = b%10
    if num_a > 0:
        arr_a.append(num_a)
    if num_b > 0:
        arr_b.append(num_b)
    a //= 10
    b //= 10


result_a = 0
result_b = 0
for i in range(len(arr_a)):
    result_a += arr_a[i]
for i in range(len(arr_b)):
    result_b += arr_b[i]
print(result_a*result_b)
