a = int(input())
b = int(input())

arrA = []
answer = 0

while b != 0:
    arrA.append(a*(b%10))
    b //= 10

for i in arrA:
    print(i)

for i in range(len(arrA) - 1, -1 , -1):
    answer *= 10
    answer += arrA[i]
print(answer)