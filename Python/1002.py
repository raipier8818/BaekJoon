import math as m

t = int(input())

for i in range(t):
    xyz = list(map(int,input().split()))

    if xyz[0] == xyz[3] and xyz[1] == xyz[4] and xyz[2] != xyz[5]:
        print(0)
        continue
    elif xyz[0] == xyz[3] and xyz[1] == xyz[4] and xyz[2] == xyz[5]:
        print(-1)
        continue

    l = m.sqrt((xyz[0]-xyz[3])**2 + (xyz[1]-xyz[4])**2)


    l2 = xyz[2]
    l3 = xyz[5]

    if l > l2 + l3 :
        print(-1)

    elif l == l2 + l3:
        print(1)
    else:
        print(2)

