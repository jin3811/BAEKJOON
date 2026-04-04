import sys
I=sys.stdin.readline

n = int(I())
mat = [list(map(int, I().split())) for _ in range(n)]
ans = [0] * n

for i in range(n):
	for j in range(n):
		ans[i] |= mat[i][j]

print(*ans)