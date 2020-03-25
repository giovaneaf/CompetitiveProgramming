N = int(input())
for i in range(0, N):
	X = int(input())
	X = 2**X
	X //= 12000
	print(str(X) + ' kg')