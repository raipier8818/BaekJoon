num = int(input())

arr = [0 for _ in range(num+1)]

def minimum(a,b):
    if a <= b:
        return a
    if b < a:
        return b

for i in range(2,num+1):
    arr[i] = arr[i-1] + 1
    if i % 3 == 0:
        arr[i] = minimum(arr[i], arr[i//3] + 1)
    if i % 2 == 0:
        arr[i] = minimum(arr[i], arr[i//2] + 1)

print(arr[num])