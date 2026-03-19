import sys
I=lambda:sys.stdin.readline().strip()

tc = int(I())

while tc:
	n = int(I())
	mem, end = [sorted(I().split()) for _ in range(2)]
	if mem == end: print("NOT", end=' ')
	print("CHEATER")
	tc-=1