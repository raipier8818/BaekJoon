n, m = map(int,input().split())
out = []

def find(depth,add):
    if depth == m:
        print(' '.join(map(str,out)))
        return

    for i in range(1,n+1):
        if add <= i:
            out.append(i)
            find(depth+1,i)
            out.pop()

find(0,0)