import sys
I = lambda : sys.stdin.readline().strip()
tc = int(I())
for _ in range(tc):
	n = int(I())
	a = map(int, I().split())
	print(sum(a) - n + 1)