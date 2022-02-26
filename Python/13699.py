def f(n):
    add=0
    if n>=2:
        for i in range(n):
            add += f(i)*f(n-i-1)
        return add
    else: return 1

n = int(input())
ans = f(n)

print(ans)