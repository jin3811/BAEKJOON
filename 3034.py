import sys
I = sys.stdin
n,w,h = map(int, I.readline().strip().split())

for stick in map(lambda x : int(x.strip()), I.readlines()):
	print("DA" if w**2 + h**2 >= stick**2 else "NE")