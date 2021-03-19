id = int(input())

id = (int(id / 1000) + int(id / 100) + int(id / 10)) % 1000
print(id)