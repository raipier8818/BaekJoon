n = int(input())

for i in range(n):
    str = input()
    if(str[0] == ')' or str[-1] == '('):
        print("NO")
        continue


    a = 0
    b = 0
    for i in str:
        if a < b:
            a = b+1
            break


        if i == ')':
            b += 1
        else:
            a += 1

    if(a == b):
        print("YES")
    else:
        print("NO")