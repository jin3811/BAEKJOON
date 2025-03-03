import sys
I = lambda : sys.stdin.readline().strip()

a, b = I(), I()

if a == "null" :
	print("NullPointerException\nNullPointerException")
elif b == "null" :
	print("false\nfalse")
else :
	print(str(a == b).lower())
	print(str(a.lower() == b.lower()).lower())