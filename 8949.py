import sys
a, b = map(int, sys.stdin.readline().strip().split())
ans = ""

while a != 0 or b != 0:
	ans = f"{a%10+b%10}{ans}"
	a //= 10
	b //= 10
print(ans)