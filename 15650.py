n, m = map(int,input().split())
visit = [0 for __ in range(n)]
out = []
def find(depth,add):
    if depth == m:
        print(' '.join(map(str,out)))
        return

    for i in range(len(visit)):
        if visit[i] == 0 and add < i+1:
            visit[i] = 1
            out.append(i+1)
            find(depth+1,i+1)
            visit[i] = 0
            out.pop()

find(0,0)