n, m = map(int,input().split())
l = []
for i in range(n):
    l.append([i+1])

string = ''
def printC(l,m,string):
    if m == 0:
        return

    for i in range(len(l)):
        print(l[i], " ", end="")
        
    return

printC(l,m)