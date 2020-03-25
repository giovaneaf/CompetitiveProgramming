import copy

try:
  while True:
    expr = input()
    opStack = []
    result = []
    inSet = False
    s = set()
    for ch in expr:
      if ch == '{':
        inSet = True
      elif ch == '}':
        inSet = False
        result.append(copy.deepcopy(s))
        s.clear()
      elif inSet:
        s.add(ch)
      else:
        if ch == ')':
          while len(opStack) > 0 and opStack[-1] != '(':
            result.append(opStack.pop())
          opStack.pop()
        elif ch == '*':
          while len(opStack) > 0 and opStack[-1] == '*':
            result.append(opStack.pop())
        elif ch == '+' or ch == '-':
          while len(opStack) > 0 and opStack[-1] != '(':
            result.append(opStack.pop())
        if ch != ')':
          opStack.append(ch)
    while(len(opStack) > 0):
      result.append(opStack.pop())
    operator = True
    while operator:
      operator = False
      for i in range(2, len(result)):
        if(result[i] == '+' or result[i] == '-' or result[i] == '*'):
          operator = True
          op = result[i]
          result.pop(i)
          s2 = result[i-1]
          result.pop(i-1)
          s1 = result[i-2]
          result.pop(i-2)
          if(op == '+'):
            s1 = s1.union(s2)
          elif(op == '-'):
            s1 = s1.difference(s2)
          else:
            s1 = s1.intersection(s2)
          result.insert(i-2, copy.deepcopy(s1))
          break
    print('{', end='')
    for i in sorted(list(result[0])):
      print(i, end='')
    print('}')
except:
  exit(0)