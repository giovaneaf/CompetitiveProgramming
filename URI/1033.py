def matMul(a, b, mod):
  tmp = [[0,0], [0,0]]
  for i in range(0, 2):
    for j in range(0, 2):
      for k in range(0, 2):
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j])%mod
  return tmp

def exp(n, mod):
  if n == 0:
    return 1
  res = [[1,0], [0,1]]
  x = [[1,1], [1,0]]
  while(n > 0):
    if(n&1):
      res = matMul(res, x, mod)
    n >>= 1
    x = matMul(x, x, mod)
  return res[0][1]  

i = 1
while True:
  n, mod = map(int, (input()).split())
  if mod == 0:
    break
  print("Case %d: %d %d %d" %(i, n, mod, (2*exp(n+1, mod)-1)%mod))
  i += 1