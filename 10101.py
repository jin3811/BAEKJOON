import sys
a,b,c = sorted(map(lambda x : int(x.strip()), sys.stdin.readlines()))

if a + b + c != 180:
	print("Error")
else:
	if a == b == c:
		print("Equilateral")
	elif a == b or b == c:
		print("Isosceles")
	else:
		print("Scalene")