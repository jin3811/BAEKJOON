import sys
I = lambda : sys.stdin.readline().strip()

tc = int(I())

for _ in range(tc):
	a, b = I().split()
	if len(a) < len(b) : a, b = b, a

	ac = int(a) * int(b)
	wa = ""

	b = "1" * (len(a) - len(b)) + b

	for i in range(len(a)):
		wa += str(int(a[i]) * int(b[i]))


	print(1 if ac == int(wa) else 0)