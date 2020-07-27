x, y = map(int,input().split())


month = [31,28,31,30,31,30,31,31,30,31,30,31]

day = 0

for i in range(x-1):
    day += month[i]

day += y
day %= 7

f = ['MON','TUE','WED','THU','FRI','SAT','SUN']

print(f[day-1])