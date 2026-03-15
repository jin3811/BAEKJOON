import sys
I=lambda:list(map(float,sys.stdin.readline().strip().split()))

tc = int(I()[0])

def get_score(x, y) :
	r2 = x**2 + y**2
	if r2 <= 9 : return 100
	elif r2 <= 36 : return 80
	elif r2 <= 81 : return 60
	elif r2 <= 144 : return 40
	elif r2 <= 225 : return 20
	else : return 0

for _ in range(tc):
	ans = [0, 0]
	darts = I()
	for i in range(0, 12, 2):
		ans[i//6] += get_score(darts[i], darts[i+1])
	print(f"SCORE: {ans[0]} to {ans[1]},", end=' ')
	if ans[0] == ans[1]: print("TIE.")
	else: print(f"PLAYER {1 if ans[0] > ans[1] else 2} WINS.")