import sys
input = sys.stdin.readline

a = int(input().strip()[:-2])*100
b = int(input())

for i in range(100):
	if (a + i) % b == 0:
		print(f"{i:02d}")
		break