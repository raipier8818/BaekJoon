n = int(input())
list = []
a = int(input())
list.append(a)
for i in range(1,n):
    a = int(input())
    for j in range(len(list)):
        if list[j] > a:
            list.insert(j,a)
            break
