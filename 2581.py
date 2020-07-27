m = int(input())
n = int(input())
nlist = []
for i in range(m,n+1):
    string = 0
    if i>1:
        for k in range(2,i):
            if i%k==0:
                string = 1
                break
            else:
                string = 0

        if string == 0:
            nlist.append(i)

if len(nlist) == 0:
    print(-1)
else:
    print(sum(nlist))
    print(nlist[0])