import time
import math

def fast_exp(x, n, mod):
	if n == 0:
		return 1
	y = 1
	while(n > 0):
		if(n & 1):
		  y = y*x % mod
		n >>= 1
		x = x*x %mod
	return y%mod

n = int(input())
n = fast_exp(2, n, 86400) - 1

print(time.strftime('%H:%M:%S', time.gmtime(n)))