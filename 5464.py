from collections import deque
import sys
I=sys.stdin.readline

ans = 0
n, m = map(int, I().split())
park_area = [0] * n
park_area_cost = tuple([int(I().rstrip()) for _ in range(n)])
car_weight = tuple([0] + [int(I().rstrip()) for _ in range(m)])
query = map(lambda x : int(x.rstrip()), sys.stdin.readlines())

wait = deque()
for q in query:
	if q > 0:
		try :
			idx = park_area.index(0)
			park_area[idx] = q
		except :
			wait.appendleft(q)
	else: 
		empty = park_area.index(-q)
		ans += car_weight[-q] * park_area_cost[empty]
		if wait:
			park_area[empty] = wait.pop()
		else :
			park_area[empty] = 0

for c, v in enumerate(park_area):
	if v == 0 : continue
	ans += park_area_cost[c] * car_weight[c]

print(ans)