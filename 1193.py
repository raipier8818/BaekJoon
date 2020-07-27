x = int(input())
i = 1  # line
count = 0
while x>0:
    x -= i
    if x>0:
        count += 1
        i+=1
    else:
        x += i
        break

if i%2 == 0:
    m = x
    n = i+1-x
    print("%d/%d"%(m,n))
else:
    m = x
    n = i + 1 - x
    print("%d/%d"%(n,m))


