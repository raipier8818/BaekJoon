arr = input().split('-')

for i in range(len(arr)):
    arr[i] = list(map(int,arr[i].split('+')))


result = sum(arr[0])
for j in range(1,len(arr)):
    result -= sum(arr[j])

print(result)