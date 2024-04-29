import sys
input=sys.stdin.readline
for _ in range(int(input().strip())):
	m,n=map(int, input().split())
	ans = 0
	for i in range(m, n+1):
		ans += str(i).count('0')
	print(ans)