h = []

for i in range(0,9):
    height = int(input())
    h.append(height)

h.sort()

for a in range(0,9):
    for b in range(0,9):
        hh = h[:]
        if a == b:
            continue
        else:
            hh.remove(h[a])
            hh.remove(h[b])

            add = 0
            for j in range(0,7):
                add += hh[j]

            if add == 100:
                break

    if add == 100:
        break

for k in range(0,7):
    print(hh[k])