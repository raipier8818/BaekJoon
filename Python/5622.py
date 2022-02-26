
alphabet = "a b c d e f g h i j k l m n o p q r s t u v w x y z"
alphabet = list(alphabet.split())

num = [2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9]

dial = {}

for i in range(len(alphabet)):
    dial[alphabet[i]] = num[i]

text = input()
text = text.lower()
text_list = list(text)

key_list = []
second = 0

for k in text_list:
    for j in range(len(alphabet)):
        if k == alphabet[j]:
            second += dial[alphabet[j]]


second += len(text_list)

print(second)


