import sys
n,m,b = map(int,input().split())

floor = []
for i in range(n):
    num = list(map(int,input().split()))
    floor += num

top, bot = max(floor), min(floor)


result_time = sys.maxsize
result_floor = 0

for f in range(bot,top+1):
    time = 0
    block = 0

    for j in floor:
        h = f - j
        if h > 0:
            time += 1*h
            block -= h
        if h < 0:
            time += 2*(-1)*h
            block -= h

    if b + block >= 0:
        if result_time >= time:
            if result_floor <= f:
                result_floor = f
                result_time = time

print(result_time,result_floor)