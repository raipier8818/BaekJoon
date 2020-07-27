def reverse(a):
    a_list = []
    for i in range(len(a)):
        a_list.append(a[len(a) - 1 -i])
    b = ''
    for j in range(len(a_list)):
        b += a_list[j]

    return b

def biggerOne(a,b):
    if a > b:
        return a
    else:
        return b


a, b = input().split()

a = reverse(a)
b = reverse(b)

print(biggerOne(a,b))


