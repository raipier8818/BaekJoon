n = int(input())


dp_1 = [0]
dp_0 = [0]

for i in range(1,n + 1):
    if i == 1:
        dp_0.append(0)
        dp_1.append(1)
    if i == 2:
        dp_0.append(1)
        dp_1.append(1)

    if i >= 3:
        dp_0.append(dp_0[-2] + dp_1[-2])
        dp_1.append(dp_0[-2] + dp_1[-1])
        dp_0.pop(0)
        dp_1.pop(0)

print(dp_0[-1] + dp_1[-1])