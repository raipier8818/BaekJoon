text = input()

c_alphabet_2 = ['c=','c-','d-','lj','nj','s=','z=']
c_alphabet_3 = 'dz='
alphabet = "a b c d e f g h i j k l m n o p q r s t u v w x y z"
alphabet = list(alphabet.split())

def countAlpha(text,count):
    if len(text) == 0:
        print(count)
        return

    if text[:3] == c_alphabet_3:
        countAlpha(text[3:],count+1)
    elif text[:2] in c_alphabet_2:
        countAlpha(text[2:],count+1)
    else:
        countAlpha(text[1:],count+1)


countAlpha(text,0)