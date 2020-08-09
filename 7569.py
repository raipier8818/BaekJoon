# import sys
# sys.setrecursionlimit(10**8)
#
# m, n, h = map(int,sys.stdin.readline().split())
#
# box = []
# for i in range(h):
#     floor = []
#     for j in range(n):
#         tomato = list(map(int,sys.stdin.readline().split()))
#         floor.append([-1] + tomato + [-1])
#
#     line = []
#     for k in range(m+2):
#         line.append(-1)
#     floor.insert(0,line)
#     floor.append(line)
#     box.append(floor)
#
# floor = []
# for aa in range(n+2):
#     line = []
#     for bb in range(m+2):
#         line.append(-1)
#     floor.append(line)
#
# box.insert(0,floor)
# box.append(floor)
#
# def r(x,y,z,count):
#     c = 0
#     box[z][y][x] = 1
#     if box[z-1][y][x] == 0:
#         if [x,y,z-1,count+1] not in q:
#             q.append([x,y,z-1,count+1])
#             c += 1
#     if box[z+1][y][x] == 0:
#         if [x, y, z + 1, count + 1] not in q:
#             q.append([x,y,z+1,count+1])
#             c += 1
#     if box[z][y-1][x] == 0:
#         if [x, y - 1, z, count + 1] not in q:
#             q.append([x,y-1,z,count+1])
#             c += 1
#     if box[z][y+1][x] == 0:
#         if [x, y + 1, z, count + 1] not in q:
#             q.append([x,y+1,z,count+1])
#             c += 1
#     if box[z][y][x+1] == 0:
#         if [x + 1, y, z, count + 1] not in q:
#             q.append([x+1,y,z,count+1])
#             c += 1
#     if box[z][y][x-1] == 0:
#         if [x - 1, y, z, count + 1] not in q:
#             q.append([x-1,y,z,count+1])
#             c += 1
#
#     for i in range(c):
#         p_x, p_y, p_z = q[0][0], q[0][1], q[0][2]
#         cc = q[0][3]
#         if cc not in count_day:
#             count_day.append(cc)
#         q.pop(0)
#         r(p_x,p_y,p_z,cc)
#
#
# count_day = []
#
# for A in range(1,m+1):
#     for B in range(1,n+1):
#         for C in range(1,h+1):
#             if box[C][B][A] == 1:
#                 q = []
#                 r(A,B,C,0)
#
#
# day = max(count_day)
# check = True
#
# for D in range(1,m+1):
#     for E in range(1,n+1):
#         for F in range(1,h+1):
#             if box[F][E][D] == 0:
#                 check = False
#                 break
#
#
# if check == True:
#     print(day)
#
# else:
#     print(-1)


import sys
sys.setrecursionlimit(10**8)

n, m, h = map(int,input().split())

visit = [[[0]*n for _ in range(m)] for __ in range(h)]


box = []
for i in range(h):
    floor = []
    for j in range(m):
        floor.append(list(map(int,input().split())))
    box.append(floor)

posX = [-1,1,0,0,0,0]
posY = [0,0,1,-1,0,0]
posZ = [0,0,0,0,1,-1]

position = []
day = []

def bfs(x,y,z,c):
    count = 0
    if visit[z][y][x] == 0:
        visit[z][y][x] = 1

    for i in range(6):
        if n > x + posX[i] >= 0 and m > y + posY[i] >= 0 and h > z + posZ[i] >= 0:
            if visit[z + posZ[i]][y + posY[i]][x + posX[i]] == 1:
                continue

            if box[z + posZ[i]][y + posY[i]][x + posX[i]] == 0:
                position.append([x + posX[i], y + posY[i], z + posZ[i], c + 1])
                visit[z + posZ[i]][y + posY[i]][x + posX[i]] = 1
                count += 1

    for j in range(count):
        x_ = position[0][0]
        y_ = position[0][1]
        z_ = position[0][2]
        c_ = position[0][3]
        if c_ not in day:
            day.append(c_)
        position.pop(0)
        bfs(x_,y_,z_,c_)


for a in range(h):
    for b in range(m):
        for c in range(n):
            if box[a][b][c] == 1:
                bfs(c,b,a,0)



for a in range(0,h):
    for b in range(0,m):
        for c in range(0,n):
            if visit[a][b][c] == 0:
                print(-1)
                exit()

if len(day) == 0:
    print(0)
else:
    print(day[-1])