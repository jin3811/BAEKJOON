import sys
import math
from itertools import permutations
npr = {}

while True:
	n = int(sys.stdin.readline().rstrip())
	if not n: break

	cnt = 0
	i = 1

	while cnt + 9 * math.perm(9, i - 1) < n : 
		cnt += 9 * math.perm(9, i - 1)
		i += 1

	if not npr.get(i):
		npr[i] = list(permutations(range(10), i))[math.perm(9,i-1):600000]
	nums = npr[i][n-cnt-1]

	print(*nums,sep='')