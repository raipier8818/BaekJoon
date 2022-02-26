a,b,c = map(int,input().split())

if b < c:
    count = a//(c-b) + 1
    print(count)
else:
    print(-1)