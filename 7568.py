num = int(input())

people = []
l = []

for i in range(num):
    w, h = map(int,input().split())
    people.append([w,h,i])

idx = 0
same = 1

for j in range(num):
    for m in range(num):
        if j != m:
            if people[j][0] < people[m][0]:
                if people[j][1] < people[m][1]:
                    idx += 1

                elif people[j][1] >= people[m][1]:
                    same += 1

            elif people[j][0] > people[m][0]:
                if people[j][1] >= people[m][1]:
                    idx += 1

                elif people[j][1] < people[m][1]:
                    same += 1
            else:
                if people[j][1] < people[m][1]:
                    same += 1

                elif people[j][1] > people[m][1]:
                    idx += 1

                else:
                    same += 1
    l.append(idx + same)
    same = 1
    idx = 0

for k in range(num):
    print(l[k]," ",end = "")

print()