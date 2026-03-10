import sys
I=lambda : sys.stdin.readline().strip()

n, m = map(int, I().split())
dup = []

for _ in range(n):
	dup.append("".join(map(lambda x : x+x, I())))

print(("Not " if dup != list(map(lambda x : x.strip(), sys.stdin.readlines())) else "") + "Eyfa")