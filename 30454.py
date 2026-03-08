import sys
I=lambda x=' ' : sys.stdin.readline().strip().split(x)

n, l = map(int, I())
ans = [-1, 0]

for _ in range(n):
	zebra = len([i for i in I('0') if i])

	if zebra > ans[0] :
		ans = [zebra, 1]
	elif zebra == ans[0]:
		ans[1] += 1


print(*ans)