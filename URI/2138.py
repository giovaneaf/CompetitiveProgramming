try:
    while True:
        str = input()
        l = [0]*10
        for number in str:
            l[int(number)] += 1
        ans = 0
        mx = l[0]
        for i in range(1, 10):
            if l[i] >= mx:
                mx = l[i]
                ans = i
        print(ans)
except:
    exit(0)