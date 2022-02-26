n = int(input())
count = 0

nList = list(map(int,input().split()))


for i in range(n):
    string = 0
    if nList[i]>1:
        for k in range(2,nList[i]):
            if nList[i]%k == 0:
                string = 1
                break
            else:
                string = 0

        if string == 0:
            count+= 1



print(count)