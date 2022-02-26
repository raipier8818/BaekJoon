n = int(input())

line = 1
space = 0

num = int(input())
star = num

while line < num:

    for a in range(0, space):
        print(" ", end="")
    for b in range(1, 2 * star):
        print("*", end="")

    print("")
    line += 1
    space += 1
    star += -1

for c in range(0, space):
    print(" ", end="")
print("*")

while line > 1:
    space += -1
    star += 1
    line += -1

    for a in range(0, space):
        print(" ", end="")
    for b in range(1, 2 * star):
        print("*", end="")

    print("")

