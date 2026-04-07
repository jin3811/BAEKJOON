import sys
I=sys.stdin.readline

n = int(I())
a = [list(map(int, I().split())) for _ in range(n)]
b = [list(map(int, I().split())) for _ in range(n)]
c = [0] * n*n
ans = 0

for i in range(n):
	for k in range(n):
		for j in range(n):
			c[i * n + j] |= a[i][k] & b[k][j]
print(c.count(1))