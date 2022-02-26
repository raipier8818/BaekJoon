n = int(input())
m = int(input())

I = 1001
II = 9999999

city = [ [II for __ in range(I)] for _ in range(I)]

for i in range(m):
    a,b,c = int(input().split())
    city[a][b] = c

A, B = int(input().split())

pq = []
visit = [0 for ___ in range(I)]


def find(temp,count):
    