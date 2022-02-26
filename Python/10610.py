n = list(map(int,input()))

if 0 in n:
    if sum(n) % 3 == 0:
        n.sort(reverse=True)
        newN = list(map(str,n))
        print(''.join(newN))
    else:
        print(-1)
else:
    print(-1)