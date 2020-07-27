m ,n=map(int,input().split())
nlist = []
for i in range(m,n+1):
    string = 0
    if i>1:
        if i%2 != 0:
            for k in range(3,i,2):
                if i%k==0:
                    string = 1
                    break
                else:
                    string = 0

        if string == 0:
            nlist.append(i)

for k in range(len(nlist)):
    print(nlist[k])