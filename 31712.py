cu, du = map(int,input().split())
cd, dd = map(int,input().split())
cp, dp = map(int,input().split())
h = int(input()) - (du + dd + dp)
t = 0

while h > 0:
	t += 1
	if t % cu == 0: h -= du
	if t % cd == 0: h -= dd
	if t % cp == 0: h -= dp

print(t)