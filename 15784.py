import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

n, a, b = I()
a -= 1
b -= 1
room = [list(I()) for _ in range(n)]

for i in range(n):
	if room[i][b] > room[a][b] or room[a][i] > room[a][b]:
		print("ANGRY")
		break
else:
	print("HAPPY")