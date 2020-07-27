s = input()

alphabet = "a b c d e f g h i j k l m n o p q r s t u v w x y z"
arr=alphabet.split()
print(arr)

word = list(s)
print(word)
for i in range(0,len(arr)):
   for k in range(0,len(word)):
       if arr[i] == word[k]:
           arr[i] = k

for j in range(0,len(arr)):
    if type(arr[j]) == str:
        arr[j] = -1

    print(arr[j],end=" ")


