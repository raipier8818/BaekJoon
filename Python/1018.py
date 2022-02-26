import sys
n, m = map(int,input().split())

board = []


for i in range(n):
    row = list(sys.stdin.readline())
    row = row[:m]
    board.append(row)

def find(start):
    count_1 = 0
    for i in range(n):
        for j in range(m):

