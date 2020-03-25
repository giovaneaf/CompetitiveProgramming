T = int(input())

for t in range(T):
    n = int(input())
    i = 0
    ones = 0
    while((1 << i) <= n):
        if (1 << i) & n:
            ones += 1
        i += 1
    print(ones)