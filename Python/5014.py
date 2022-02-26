import sys
sys.setrecursionlimit(10**8)

f, s, g, u, d = map(int,input().split())
count = int(0)
dp = [0 for _ in range(f+1)]

global check
check = False
def pressButton(count, h):
    global check
    if 0 < h <= f:
        if h == g:
            print(count)
            check = True
            return
        if dp[h] == 0:
            dp[h] = 1
            pressButton(count + 1, h + u)
            pressButton(count + 1, h - d)

    else:
        return

pressButton(0,s)

if check == False:
    print('use the stairs')