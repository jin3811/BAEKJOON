import sys
I=lambda:map(int,sys.stdin.readline().strip().split())
tc = 1

while True:
	a,b,c = I()
	if a == b == c == 0: break

	print(f"Triangle #{tc}")
	tc += 1

	if c == -1:
		c = (a**2 + b**2) ** 0.5
		print(f"{c = :.3f}\n")

	elif a == -1:
		a = c**2 - b**2
		if a <= 0:
			print("Impossible.\n")
		else:
			a = a**0.5
			print(f"{a = :.3f}\n")

	else:
		b = c**2 - a**2
		if b <= 0:
			print("Impossible.\n")
		else:
			b = b**0.5
			print(f"{b = :.3f}\n")