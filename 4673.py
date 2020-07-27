num_list = []
real_num = []
for i in range(1,10001):
    real_num.append(i)
allnum = set([])
num = 1
add = 0
while add <= 10000:
    num_copy = num
    num_add = []
    if num >= 10:
        while num_copy // 10 != 0:
            num_add.append(num_copy%10)
            num_copy = num_copy//10
        num_add.append((num_copy))
    else:
        num_add.append(num)

    add = 0
    for i in range(len(num_add)):
        add += num_add[i]

    add += num
    if add<=10000:
        num_list.append(add)
    num += 1

real_num.sort()
num_list.sort()
s1 = set([])
s2 = set([])
s1.update(real_num)
s2.update(num_list)
allnum = s1 - s2

allnum = list(allnum)
allnum.sort()
for k in range(len(allnum)-3):
    print(allnum[k])

