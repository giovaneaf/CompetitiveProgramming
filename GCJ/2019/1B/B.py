import sys

'''
Code to find the "magic numbers" where you can see what is happening applying the modulo

def fastPow(x, n, mod):
	if(n == 0):
		return 1;
	if(n&1):
		return (x*fastPow((x*x)%mod, n//2, mod))%mod
	return fastPow((x*x)%mod, n//2, mod)

mod = 2**63
for i in range(1, 501):
	l = [fastPow(2, i//y, mod) for y in range(1, 7)]
	print(i, l)
'''
	
T, w = [int(x) for x in input().split()]
R = [0]*6

for t in range(1, T+1):
	print(227)
	sys.stdout.flush()
	ans = int(input())
	R[5] = (ans%35184372088832)//137438953472
	ans -= R[5]*137438953472
	R[4] = (ans%72057594037927936)//35184372088832
	ans -= R[4]*35184372088832
	R[3] = ans//72057594037927936
	print(56)
	sys.stdout.flush()
	ans = int(input())
	ans -= (16384*R[3] + 2048*R[4] + 512*R[5])
	R[2] = (ans%268435456)//262144
	ans -= R[2]*262144
	R[1] = (ans%72057594037927936)//268435456
	ans -= R[1]*268435456
	R[0] = ans//72057594037927936
	print(R[0], R[1], R[2], R[3], R[4], R[5])
	verdict = int(input())
	if(verdict == -1):
		break
