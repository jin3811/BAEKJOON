import sys
I = map(lambda x : x.strip(), sys.stdin.readlines())

if I[1] == "+":
	print(int(I[0])+int(I[2]))
else:
	print(int(I[0])*int(I[2]))