n_m = list(map(int,input().split()))

num_arr = list(map(int,input().split()))

add_arr = []

for i in range(n_m[1]):
    numadd = list(map(int,input().split()))
    add = 0
    for k in range(numadd[0]-1,numadd[1]):
        add += num_arr[k]

    add_arr.append(add)

for j in range(len(add_arr)):
    print(add_arr[j])