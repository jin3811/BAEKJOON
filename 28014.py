import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

I()
towers = list(I())
ans = 1
prev = towers[0]
for tower in towers[1:]:
	if prev <= tower: 
		ans += 1
	prev = tower

print(ans)