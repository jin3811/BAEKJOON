import sys
I=lambda:map(int,sys.stdin.readline().split())
w,h,x,y,n = I()

def is_inner(px, py):
	if y <= py <= y + h:
		if x <= px <= x + w:
			return True
		dy = (py-y-h//2)
		dx = (px - (x+w if px > x else x))
		return dx**2 + dy**2 <= (h//2)**2
	else:
		return False

ans = 0
for px, py in [I() for _ in range(n)]:
	if is_inner(px, py):
		ans+=1
print(ans)