T = int(input())

for i in range(T):
    n = int(input())
    low = 1
    high = 10**10
    while(low < high):
        mid = (low+high)//2
        f = (mid*(mid+1))//2
        if(f > n):
            high = mid
        else:
            low = mid+1
    if((low*(low+1))//2 != n):
        low -= 1
    print(low)