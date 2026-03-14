import sys
import re

I=lambda:sys.stdin.readline().strip()

n = int(I())
game = [I() for _ in range(n)]
s = int(I())
hubos = set([I() for _ in range(s)]) - set(game)

idx = game.index("?")

test = ""
if idx > 0:
	test += game[idx-1][-1]

test += "[a-zA-Z]*"

if idx < n-1:
	test += game[idx+1][0]

for hubo in hubos:
	if re.fullmatch(test, hubo):
		print(hubo)