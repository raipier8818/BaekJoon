case = int(input())
caselist = []
for i in range(case):
    floor,box,num = map(int,input().split())
    caselist.append([floor,box,num])

for j in range(case):
    a=1
    b=0
    while caselist[j][2]>caselist[j][0]:
       a += 1
       caselist[j][2]-=caselist[j][0]

    b = str(caselist[j][2])
    if a<10:
        a = str(0)+str(a)
    result = str(b)+str(a)
    print(result)




