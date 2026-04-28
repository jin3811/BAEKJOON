import sys
input = sys.stdin.readline

for _ in range(3):
	n = int(input().strip())
	sum = 0

	for _ in range(n):
		sum += int(input())
	
	if sum > 0 : print('+')
	elif sum < 0 : print('-')
	else : print(0)