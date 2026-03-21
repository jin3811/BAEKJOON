import sys
I=sys.stdin.readline

n = int(I())
stu = {n:0 for n in I().split()}
for _ in range(n):
	for name in I().split():
		stu[name] += 1
for v, k in sorted([(-v, k) for k,v in stu.items()]):
	print(k, -v)