num = int(input())
j = 0
u = 0
numarr = []
add = 0

for i in range(1,num):
    j = num - i
    numarr = []
    u = i
    while (i % 10 != 0):
        l = i % 10
        numarr.append(l)
        i = i//10

    add = 0
    for k in range(len(numarr)):
        add += numarr[k]

    if (u + add == num):
        break

if (u+add == num):
    print(u)

else:
    print("0")