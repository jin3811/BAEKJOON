import sys
I=sys.stdin.readline

I()
garden = list(map(int, I().split()))

for _ in range(int(I())):
	q = list(map(int,I().split()))
	if q[0] == 1:
		cnt = 0
		l, r, k = map(int, q[1:])
		for i in range(l-1, r):
			if garden[i] == k: cnt+=1
		print(cnt)
	elif q[0] == 2:
		l, r = map(int, q[1:])
		for i in range(l-1, r):
			garden[i] = 0