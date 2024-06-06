import re

def parse(exp):
	m = re.match(r'(-?\d+)([\+\-\*/])(-?\d+)', exp)
	if m:
		a = int(m.group(1), 8)
		op = m.group(2)
		b = int(m.group(3), 8)
		return a, op, b

a, op, b = parse(input())
res = 0

if op == '+':
	res = a + b
elif op == '-':
	res = a - b
elif op == '*':
	res = a * b
elif op == '/':
	if b == 0 :
		print("invalid")
		exit(0)
	else : res = a // b

if res < 0:
    print(f"-{oct(res)[3:]}")
else :
	print(oct(res)[2:])