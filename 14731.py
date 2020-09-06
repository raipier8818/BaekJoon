import sys
sys.setrecursionlimit(10**8)

def mod(b):
    if b < 0:
        return 0
    if b == 0:
        return 1
    else:
        if b % 2 == 1:
            return mod(b//2)**2 * 2 % (10**9+7)
        else:
            return mod(b//2)**2 % (10**9+7)



n = int(sys.stdin.readline())

sum = 0
for i in range(n):
    a, b = map(int,sys.stdin.readline().split())

    sum += a*b*mod(b-1)
    sum %= (10**9+7)

print(sum)