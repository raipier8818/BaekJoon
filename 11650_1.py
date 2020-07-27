num = int(input())

list_ = []

for i in range(num):
    point = list(map(int,input().split()))
    list_.append(point)

list_.sort(key = lambda x:x[1])
list_.sort(key = lambda x:x[0])

for k in range(num):
    print(list_[k][0], list_[k][1])