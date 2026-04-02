import sys
I = sys.stdin.readline

for _ in range(n:=int(I())):
	ans = 0
	mis = [map(int, I().split()) for _ in range(int(I()))]
	kda = list(map(int, I().split()))
	kda[1] *= -1

	for a in mis:
		ans += max(0, sum([i*j for i,j in zip(a,kda)]))

	print(ans)