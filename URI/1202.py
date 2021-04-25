
f0 = 0
f1 = 1

ans = [0, 1]
pp = 0

mod = 1000

while(True):
	f0, f1 = f1, (f0+f1)%mod
	ans.append(f1)
	pp += 1
	if(f0 == 0 and f1 == 1):
		break

T = int(input())

for t in range(T):
	n = int(input(), 2)
	print('{:03}'.format(ans[n%pp]))