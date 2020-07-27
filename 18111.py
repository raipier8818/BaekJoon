a = list(map(int,input().split()))
ver = a[0]
hor = a[1]
inventory = a[2]

location = []

for i in range(0,ver):
    ver_list = list(map(int,input().split()))
    location.append(ver_list)

#######################################################

add = 0
count = 0

for k in range(0,ver):
    for j in range(0,hor):
        add = add + location[k][j]



average = add/(ver*hor)

for k in range(0,ver):
    for j in range(0,hor):
        if location[k][j] > average:
            count += 1




