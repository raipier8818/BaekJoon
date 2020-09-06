import sys
sys.setrecursionlimit(10**8)

def dps(p,l,count):
    if p >= y-1:
        if y-1 == p:
            r.add(count+1)
            return
        else:
            return

    if l-1 > 0:
        dps(p+l-1,l-1,count+1)

    if l != 0:
        dps(p+l,l,count+1)

    dps(p+l+1,l+1,count+1)




test = int(input())

for i in range(test):
    r = set()
    x,y = map(int,input().split())
    dps(x,0,0)
    print(min(r))

    

