num, n = map(int,input().split())

list = [0]

for i in range(1,num+1):
    if(num%i == 0):
        list.append(i)

if (len(list)-1<n):
    print(list[0])

else:
    print(list[n])