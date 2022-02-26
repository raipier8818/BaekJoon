import sys
n = int(sys.stdin.readline())


time = []
for i in range(n):
    time.append(list(map(int,sys.stdin.readline().split())))

time = sorted(time, key=lambda x : x[0])
time = sorted(time, key=lambda x : x[1])

count = 0
m = 0
for meet in time:
    if meet[0] >= m:
        m = meet[1]
        count += 1

print(count)