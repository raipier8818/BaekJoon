n, m = map(int,input().split())
out = []
def find(depth):
    if depth == m:
        print(' '.join(map(str,out)))
        return

    for i in range(1,n+1):
        out.append(i+1)
        find(depth+1)
        out.pop()

find(0)