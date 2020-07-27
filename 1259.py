str = ''

while str != '0':
    str = input()
    if str == '0':
        break
    mid = len(str)//2
    boolen = 0
    if len(str)%2 == 0:
        for i in range(mid):
            if str[i] != str[len(str)-i-1]:
                boolen = 1

    else:
        for j in range(mid):
            if str[j] != str[len(str)-j-1]:
                boolen = 1

    if boolen == 1:
        print('no')
    else:
        print('yes')