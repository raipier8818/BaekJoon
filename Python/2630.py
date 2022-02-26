n = int(input())

arr = []

for i in range(n):
    arr.append(list(map(int,input().split())))

def convert(start_x,start_y,end_x,end_y):
    for y in range(start_y,end_y):
        for x in range(start_x,end_x):
            if arr[x][y] == 1:
                arr[x][y] = -1
    return

def convert_copy(start_x,start_y,end_x,end_y):
    for y in range(start_y,end_y):
        for x in range(start_x,end_x):
            if arr[x][y] == 0:
                arr[x][y] = -1
    return

def checkSquare(start_x,start_y,end_x,end_y):
    if arr[start_x][start_y] == -1:
        return 0

    for y in range(start_y,end_y):
        for x in range(start_x,end_x):
            if arr[x][y] == 0:
                return 0

    convert(start_x, start_y, end_x, end_y)
    return 1

def checkSquare_copy(start_x,start_y,end_x,end_y):
    if arr[start_x][start_y] == -1:
        return 0

    for y in range(start_y,end_y):
        for x in range(start_x,end_x):
            if arr[x][y] == -1:
                return 0

    convert_copy(start_x, start_y, end_x, end_y)
    return 1

count_blue = 0
count_white = 0

size = [128,64,32,16,8,4,2,1]
time = 1

for i in size:
    if i <= n:
        for y in range(0,time):
            for x in range(0,time):
                count_blue += checkSquare(x*i,y*i,(x+1)*i,(y+1)*i)

        time *= 2

time_ = 1
for i in size:
    if i <= n:
        for y in range(0,time_):
            for x in range(0,time_):
                count_white += checkSquare_copy(x*i,y*i,(x+1)*i,(y+1)*i)

        time_ *= 2

print(count_white)
print(count_blue)