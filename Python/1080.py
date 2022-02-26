import sys

n, m = map(int,sys.stdin.readline().split())
matrix1 = []
matrix2 = []
for i in range(n):
    matrix1.append(list(sys.stdin.readline())[:m])
for i in range(n):
    matrix2.append(list(sys.stdin.readline())[:m])


def reverse(origin):
    if origin == '1':
        return '0'
    else:
        return '1'


def swap(x,y):
    for i in range(x,x+3):
        for j in range(y,y+3):
            matrix1[i][j] = reverse(matrix1[i][j])


if n >= 3 and m >= 3:
    count = 0
    for i in range(n-2):
        for j in range(m-2):
            if matrix1[i][j] != matrix2[i][j]:
                swap(i,j)
                count += 1

    if matrix1 == matrix2:
        print(count)
    else:
        print(-1)

else:
    if matrix1 == matrix2:
        print(0)
    else:
        print(-1)
