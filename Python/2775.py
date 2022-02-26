apartment = [[0 for __ in range(15)] for _ in range(15)]

for m in range(15):
    apartment[m][1] = 1
    apartment[0][m] = m


def find(k,n):
    if n == 1 or k == 0:
        return

    if apartment[k][n] == 0:
        find(k-1,n)
        find(k,n-1)

        apartment[k][n] = apartment[k-1][n] + apartment[k][n-1]



test = int(input())

for i in range(test):
    k = int(input())
    n = int(input())
    find(k,n)
    print(apartment[k][n])