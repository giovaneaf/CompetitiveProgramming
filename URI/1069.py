n = int(input())

while(n > 0):
    s = input()
    stack = []
    diamonds = 0
    for word in s:
        if(word == '<'):
            stack.append('<')
        elif(word == '>' and len(stack) > 0):
            diamonds += 1
            stack = stack[:len(stack)-1]
    print(diamonds)
    n -= 1
