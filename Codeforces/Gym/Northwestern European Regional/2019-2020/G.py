import sys

sys.setrecursionlimit(1000000)

memo = dict()

def combination(n, k):
	if(k > n):
		return 0
	if(k == 0 or k == n):
		return 1
	if((n, k) not in memo):
		memo[(n, k)] = combination(n-1, k-1) + combination(n-1, k)
	return memo[(n, k)]

n, k = [int(x) for x in input().split()]

v = [float(x) for x in input().split()]
ans = [0]*n

if(k == 1):
	for i in range(n):
		if(i > 0):
			print(' ', end='')
		print(100/n, end='')
	print('')
	exit(0)

division = combination(n, k)

for i in range(n):
	ptr = (i-1+n)%n
	acc = v[i]
	res = 0
	sub = 2
	while(ptr != i):
		res += acc*combination(n-sub, k-2)
		acc += v[ptr]
		sub += 1
		ptr = ptr-1 if ptr > 0 else n-1
	ans[i] = res/division
	
for i in range(n):
	if(i > 0):
		print(' ', end='')
	print(ans[i], end='')
print('')