import sys
I=lambda:int(sys.stdin.readline().strip())

times = (300, 60, 10)
t = I()
if t % 10 != 0: print(-1)
else:
	for time in times:
		print(f"{t // time}", end=' ')
		t %= time
	print()