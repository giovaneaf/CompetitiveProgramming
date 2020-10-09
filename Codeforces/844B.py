
n, m = list(map(int, input().split()))

M = []

for i in range(n):
    num = list(map(int, input().split()))
    M.append(num)

ans = 0

for i in range(n):
    cnt = 0
    for j in range(m):
        if(M[i][j] == 1):
            cnt += 1
    ans += 2**cnt - 1
    ans += 2**(m-cnt) - 1

for j in range(m):
    cnt = 0
    for i in range(n):
        if(M[i][j] == 1):
            cnt += 1
    ans += 2**cnt - 1
    ans += 2**(n-cnt) - 1
    ans -= n

print(ans)
