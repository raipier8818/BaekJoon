num = int(input())

for i in range(1,num):
    for k in range(1,num-i+1):
        print(" ",end="")
    for j in range(k+1,num+1):
        print("*",end="")
    print()

print("*"*num)

for i in range(num-1,0,-1):
    for k in range(1,num-i+1):
        print(" ",end="")
    for j in range(k+1,num+1):
        print("*",end="")
    print()