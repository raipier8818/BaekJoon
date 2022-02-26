num = int(input())

list_ = []

for i in range(num):
    point = list(map(int,input().split()))
    list_.append(point)

for k in range(num-1):
    min_ind = k
    for j in range(k+1,num):
        if list_[min_ind][0] > list_[j][0]:
            min_ind = j
    list_[min_ind], list_[k] = list_[k], list_[min_ind]

for m in range(num-1):
    if list_[m][1] > list_[m+1][1]:
        list_[m],list_[m+1] = list_[m+1],list_[m]

for n in range(num):
    print(list_[n][0], list_[n][1])