n = int(input())
b = 2
can = True

l = [int(x) for x in input().split()]

for x in l:
	if(x > b):
		can = False
	if(can):
		b -= x
	b *= 2

b //= 2

if(can):
	print(b%1000000007)
else:
	print('error')
