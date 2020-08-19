def p(a,n):
    if n == 1:
        return a%c
    if n%2 == 0:
        return p(a,n//2)**2%c
    if n%2 == 1:
        return p(a,n//2)**2*a%c

a,b,c = map(int,input().split())

print(p(a,b))