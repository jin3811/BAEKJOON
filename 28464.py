from collections import deque
import sys
I=sys.stdin.readline

n = int(I())
potato = deque(sorted(map(int, I().split())))
ans = [0, 0]

while n:
	if n & 1 : ans[1] += potato.pop()
	else : ans[0] += potato.popleft()
	n -= 1

print(*ans)