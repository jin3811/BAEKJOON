import sys
I = lambda : sys.stdin.readline().strip()
tc = int(I())
for _ in range(tc):
	l,r,d,u = map(lambda x : abs(int(x)), I().split())
	print("Yes" if l == r == d == u else "No")