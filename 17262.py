import sys
s, e = 2**31, -1
for a, b in map(lambda x : map(int,x.split()), sys.stdin.readlines()[1:]):
	s = min(s, b)
	e = max(e, a)
print(e - s if e - s > 0 else 0)