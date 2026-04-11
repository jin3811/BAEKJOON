import sys
I=lambda:map(int,sys.stdin.readline().split())

scale = [0, 0]
ans = 0
weights = [100, 50, 20, 10, 5, 2, 1]

I()
scale[0], scale[1], *query = I()

for w in query:
	if scale[0] <= scale[1] : scale[0] += w
	else: scale[1] += w
gap = abs(scale[0] - scale[1])

while gap :
	for w in weights:
		if gap >= w :
			ans += gap // w
			gap %= w
			break
print(ans)