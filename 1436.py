n = int(input())
num = 0
count = 0
while True:
    count += 1
    if '666' in str(count):
        num += 1
        if num == n:
            print(count)
            break