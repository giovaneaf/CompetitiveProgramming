
def f(x):
  x += 1
  s = 0
  for i in range(0, 65):
    power = 1 << (i+1);
    if((power >> 1) > x):
      break
    tmp = x%power
    if(tmp > (power >> 1)):
      tmp -= (power >> 1)
    else:
      tmp = 0;
    aux = (x//power)*(1 << i) + tmp
    s += (x//power)*(1 << i) + tmp
  return s

'''for i in range(100):
  print("{}  is {}".format(i, f(i)))'''


try:
  while(True):
    a, b = input().split()
    a = int(a)
    b = int(b)
    print(f(b) - f(a-1))
except:
  exit(0)