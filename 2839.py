a = int(input())
count = a//5

a_copy = a%5

if a>=5:
    while a_copy%3 != 0 and a_copy < a:
        a_copy += 5
        count += -1


if a_copy%3 == 0:
    count += a_copy//3

else:
    count = -1

print(count)