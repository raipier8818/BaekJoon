n = int(input())

row = [0 for _ in range(n)]


count = 0

def check(y):
    for i in range(y):
        if row[i] == row[y] or abs(row[i] - row[y]) == y - i:
            return False
    return True


def find(y):
    global count
    if y == n:
        count += 1
        return

    for x in range(n):
        row[y] = x
        if check(y):
            find(y+1)

find(0)
print(count)