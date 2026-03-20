import sys
from itertools import combinations
I=lambda:map(int,sys.stdin.readline().strip().split())

def is_prime(x):
	for i in range(2, int(x**0.5) + 1):
		if x % i == 0 : return False
	return True

n, m = I()
cow = sorted(set(filter(is_prime, map(lambda x : sum(x), combinations(I(), m)))))
if len(cow) : print(*cow)
else : print(-1)