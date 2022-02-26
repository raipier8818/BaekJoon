a,b,v = map(int,input().split())
count = (v - a) // (a - b)
rest = (v - a) % (a - b)

if v-a > a-b:
else:

print(count)
