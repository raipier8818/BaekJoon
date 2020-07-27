num = list(map(int,input().split()))
price = num[1]
coin = []

for i in range(0,num[0]):
    coin_price = int(input())
    coin.append(coin_price)


count = 0
k = 1

while price != 0:
    while k < len(coin):
        if price // coin[k] == 0:
            count = count + price // coin[k - 1]
            price = price % coin[k - 1]
            k = 1
            if price == 0:
                break
        k += 1


print(count)

