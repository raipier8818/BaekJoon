num = int(input())
i = 1

while num-1>0:
    an = 6*(i-1)
    num += -1*an
    if num-1>0:
        i+=1

print(i)
