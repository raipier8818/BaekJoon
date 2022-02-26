text = input()
text = text.lower()

text_list = list(text)
text_list.sort()


alphabet = "a b c d e f g h i j k l m n o p q r s t u v w x y z"
alphabet = list(alphabet.split())
alphabet_copy = []

for k in range(len(alphabet)):
    count = 0
    for i in range(0,len(text_list)):
        if alphabet[k] == text_list[i]:
            count += 1

    alphabet_copy.append(count)


dic = {}

for m in range(len(alphabet)):
    dic[alphabet[m]] = alphabet_copy[m]


for n in range(len(dic)):
    if dic[alphabet[n]] == 0:
        del dic[alphabet[n]]


dic = sorted(dic.items(), key=lambda x : x[1], reverse = True)


if len(dic) == 1:
    print(dic[0][0].upper())

else:
    if dic[0][1] == dic[1][1]:
        print('?')
    else:
        print(dic[0][0].upper())