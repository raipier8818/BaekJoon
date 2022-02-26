def find(index, r, s):
    if index == n - 1:
        result.append(r)
        # print(s,'=',r)
        return

    if c[0] > 0:
        c[0] -= 1
        find(index + 1, r + arr[index + 1],s+'+'+str(arr[index+1]))
        c[0] += 1

    if c[1] > 0:
        c[1] -= 1
        find(index + 1, r - arr[index + 1],s+'-'+str(arr[index+1]))
        c[1] += 1

    if c[2] > 0:
        c[2] -= 1
        find(index + 1, r * arr[index + 1],s+'*'+str(arr[index+1]))
        c[2] += 1

    if c[3] > 0:
        c[3] -= 1
        if r < 0:
            r *= -1
            rr = -1*(r//arr[index+1])
        else:
            rr = r//arr[index+1]


        find(index + 1, rr ,s+'/'+str(arr[index+1]))
        c[3] += 1


n = int(input())

arr = list(map(int,input().split()))
c = list(map(int,input().split()))

copy = c[:]

result = []

find(0,arr[0],str(arr[0]))
print(max(result))
print(min(result))