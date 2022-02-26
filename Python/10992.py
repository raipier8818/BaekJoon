n = int(input())

for i in range(n):
    for j in range(n-i-1):
        print(' ',end="")

    if i == 0 or i == n-1:
        print('*'*(2*i+1))
    else:
        print('*',end="")
        print(' '*(2*i-1),end="")
        print('*')