n = int(input())

for i in range(n):
    inp = input()
    k = inp.count('!')
    inp = int(inp.replace('!',''))
    cnt = 0
    ans = 1
    while(inp - cnt*k > 1):
        ans *= (inp-cnt*k)
        cnt += 1
    print(ans)