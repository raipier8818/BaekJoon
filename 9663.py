import sys
sys.setrecursionlimit(10**8)
n = int(input())


visit = [[0 for _ in range(n)] for __ in range(n)]
count = 0
def checkPosition(row,column):
    for i in range(row-1,-1,-1):
        if visit[i][column] == 1:
            return False

    for i in range(1,n):
        if column + i < n and visit[row-i][column+i] == 1:
            return False
        if column - i >= 0 and visit[row-i][column-i] == 1:
            return False

    return True


def find(row):
    global count
    if row == n:
        count += 1
        return

    for i in range(n):
        check = checkPosition(row,i)
        if check == True:
            visit[row][i] = 1
            find(row+1)
            visit[row][i] = 0




find(0)
print(count)