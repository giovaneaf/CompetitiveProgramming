
n, s  = [int(x) for x in input().split()]

lst = []

for i in range(n):
	name, bet = input().split()
	bet = int(bet)
	lst.append((name, bet))

lst.sort(key=lambda x:x[1])
acc = [0]*n

acc[0] = lst[0][1]
for i in range(1, n):
	acc[i] = acc[i-1] + lst[i][1]

ans = []
pos = len(lst)-2

while(pos >= 0):
	if(s > acc[pos]):
		ans.append(lst[pos+1][0])
		s -= lst[pos+1][1]
	pos -= 1

if(s > 0):
	ans.append(lst[0][0])
	s -= lst[0][1]

if(s == 0):
	print(len(ans))
	for name in ans:
		print (name)
else:
	print('0')