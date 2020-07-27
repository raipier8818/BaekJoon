cardnum, addnum = input().split()

cardnum = int(cardnum)
addnum = int(addnum)

cardArr = list(map(int,input().split()))
add_arr = []



for j in range(cardnum):
    for k in range(cardnum):
        for n in range(cardnum):
            if (j < k < n):
                add = cardArr[j] + cardArr[k] + cardArr[n]
                add_arr.append(add)


for l in range(len(add_arr)):
    if add_arr[l] > addnum:
        add_arr[l] = 0
add_arr.sort(reverse=True)


print(add_arr[0])



