import sys
import re
def input() : return sys.stdin.readline().strip()

curr = list(map(int, input().split(":")))
curr[0] %= 12
papul = list(map(int, input().split()))
n = int(input())

for _ in range(n):
	query = input().split()[1]
	
	if query == "^":
		papul[curr[0] // 2] = 0
	
	elif "MIN" in query:
		m = int(re.findall(r'\d+', query)[0])
		curr[1] += m
		curr[0] += curr[1] // 60
		curr[0] %= 12
		curr[1] %= 60

	elif "HOUR" in query:
		h = int(re.findall(r'\d+', query)[0])
		curr[0] += h
		curr[0] %= 12

print(min(sum(papul), 100))