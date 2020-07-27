test = input()

ans = test

if len(test) == 1:
    test += '0'

num = ''
count = 0
while num != ans:
    if len(test) == 1:
        test = '0' + test

    num = str(int(test[0]) + int(test[1]))


    num = test[-1] + num[-1]
    print(num)

    test = num
    count += 1
    if int(ans) == int(test):
        break

print(count)