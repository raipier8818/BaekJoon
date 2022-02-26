n = int(input())

arr = [1,1]
for i in range(2,n):
    arr.append(0)
    arr[i] = arr[i-1] + arr[i-2]
print(arr[n-1])
