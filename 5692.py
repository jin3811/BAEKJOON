import sys

while True:
	i = sys.stdin.readline().rstrip()[::-1]
	if i == '0' : break

	base = 1
	ans = 0
	for n, w in zip(i, range(1, len(i)+1)):
		base *= w
		ans += int(n) * base
	print(ans)