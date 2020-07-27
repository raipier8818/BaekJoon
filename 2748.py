a = int(input())

arr = [0,1]

num = 0
for i in range(a-1):
    num = arr[i] + arr[i+1]
    arr.append(num)

print(arr[-1])