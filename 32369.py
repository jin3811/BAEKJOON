n, a, b = map(int, open(0).readline().split())
o1, o2 = 1, 1
while n:
	n -= 1
	o1 += a
	o2 += b
	if o1 < o2 : o1, o2 = o2, o1
	if o1 == o2 : o2 -= 1
print(o1, o2)