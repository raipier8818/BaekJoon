n = int(input())

arr = []

for i in range(n):
    card = int(input())
    arr.append(card)

arr = sorted(arr)
dp1 = [0 for _ in range(len(arr))]

dp1[0] = arr[0]

for i in range(1, len(arr)):
    