t = int(input())

def krapekar(x):
    cnt = 0
    while(x != '6174'):
        low = ''.join(sorted(x))
        high = low[::-1]
        x = str(int(high) - int(low))
        x = '0'*(4-len(x)) + x
        cnt += 1
    return cnt

for i in range(t):
    x = input()
    x = '0'*(4-len(x)) + x
    print("Caso #{}: ".format(i+1), end = '')
    if(x[0] != x[1] or x[1] != x[2] or x[2] != x[3]):
        print(krapekar(x))
    else:
        print('-1')