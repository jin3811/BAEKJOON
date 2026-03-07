import sys
I=sys.stdin

s, c = map(int, I.readline().strip().split())
gonion = sorted(map(lambda x : int(x.strip()), I.readlines()))
l, r, mid = 1, gonion[-1], 0

def check(length):
	cnt = 0
	for pa in gonion:
		cnt += pa // length
	return cnt >= c

while l <= r:
	mid = (l + r) // 2

	if check(mid):
		l = mid + 1
	else:
		r = mid - 1

print(sum(gonion) - r * c)