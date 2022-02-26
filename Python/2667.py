n = int(input())
apartment = []
r = []
w = []

global count_apartment

def count(x, y):
    global count_apartment
    count_apartment += 1
    apartment[x][y] = '0'
    if apartment[x-1][y] == '1':
        count(x-1,y)
    if apartment[x+1][y] == '1':
        count(x+1,y)
    if apartment[x][y+1] == '1':
        count(x,y+1)
    if apartment[x][y-1] == '1':
        count(x,y-1)

    return count_apart


for j in range(n+2):
    r.append('0')
apartment.append(r)


for i in range(n):
    o = list((input()))
    o.insert(0,'0')
    o.append('0')
    apartment.append(o)


for j in range(n+2):
    w.append('0')

apartment.append(w)


c = 0
count_apart = []

for A in range(1,n+1):
    for B in range(1,n+1):
        count_apartment = 0
        if apartment[A][B] == '1':
            count(A,B)
            c += 1
            count_apart.append(count_apartment)

print(c)
count_apart.sort()
for l in range(len(count_apart)):
    print(count_apart[l])