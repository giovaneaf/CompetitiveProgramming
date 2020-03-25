while(True):
    num = input()
    if(len(num) >= 2 and num[1] == 'x'):
        num = int(num, 16)
        print(num)
    else:
        num = int(num)
        if(num == -1):
            break
        print(hex(num)[0:2] + hex(num)[2:].upper())