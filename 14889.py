n = int(input())

stat = []
for i in range(n):
    row = list(map(int,input().split()))
    stat.append(row)

print(stat)

s1 = 0
s2 = 0

visit = [0 for _ in range(n)]

def finds1(val, count):
    
