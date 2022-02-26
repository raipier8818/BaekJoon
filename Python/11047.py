n, k = map(int,input().split())
coin = []

for i in range(n):
    c = int(input())
    if c < k:
        coin.append(c)

count = 0
index = len(coin) - 1

while k > 0:
    count += k // coin[index]
    k %= coin[index]
    index -= 1

print(count)
