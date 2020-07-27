num = int(input())
count = 0

n = 1
while n < num and num > 2 :
    n *= 3
    count += 1

while n < num:
    n *= 2
    count += 1


print(count)


'''
3x+2y-z = num
x+y+z의 최솟값?
'''