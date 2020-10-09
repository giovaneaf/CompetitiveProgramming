
n = input()

stra = input()

cnt = 0

ans = stra[0] + stra[1]

for i in range(0, len(stra)-1):
	st = stra[i] + stra[i+1]
	num = 0
	for j in range(i+1, len(stra)):
		if(st == stra[j-1] + stra[j]):
			num += 1
	if(num > cnt):
		cnt = num
		ans = st
print(ans)