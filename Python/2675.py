line = int(input())
arr = []


for i in range(0,line):
    printtext = ''
    cycletext, text = input().split()
    cycle = int(cycletext)
    for k in range(0,len(text)):
        printtext = printtext + text[k]*cycle

    arr.append(printtext)

for j in range(0,line):
    print(arr[j])