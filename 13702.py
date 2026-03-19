import sys
I=lambda:sys.stdin.readline()

n, k = map(int, I().strip().split())
bottles = [int(I()) for _ in range(n)]
l, r = 1, max(bottles)

check = lambda x : sum(map(lambda ml : ml // x, bottles))

while l <= r:
	mid = (l + r) // 2
	if check(mid) >= k:
		l = mid + 1
	else :
		r = mid - 1

print(r)