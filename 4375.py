import sys
input = sys.stdin.readline

def sol(n) :
	a = "1"
	while int(a) % n != 0 : a += "1"
	return len(a)

while True:
	tmp = input().rstrip()
	if tmp == "" : break
	print(sol(int(tmp)))