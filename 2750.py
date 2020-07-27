def sort(a):
    for i in range(len(a)-1):
        min_inx = i
        for j in range(i+1,len(a)):
            if a[min_inx] > a[j]:
                min_inx = j
        a[min_inx], a[i] = a[i], a[min_inx]
    return a

n = int(input())
list = []
for i in range(n):
    num = int(input())
    list.append(num)

list = sort(list)

for k in range(n):
    print(list[k])