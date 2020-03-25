year = 0

i = 0

while(True):
	try:
		year = input()
		if i != 0:
			print ''
		leapyear = (year%4 == 0 and year%100 != 0) or (year%400 == 0)
		ordinaryyear = True
		if leapyear:
			print "This is leap year."
			ordinaryyear = False
		if year%15 == 0:
			print "This is huluculu festival year."
			ordinaryyear = False
		if (leapyear and year%55 == 0):
			print "This is bulukulu festival year."
		if ordinaryyear:
			print "This is an ordinary year."
		i = 1
	except EOFError:
		break