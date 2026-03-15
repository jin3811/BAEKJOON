import sys

sub = sys.stdin.readlines()[1].strip()
big = 0
sec = 0
i = 0

while i < len(sub):
	if sub[i] == 'b':
		big += 1
		i += 7
	elif sub[i] == 's':
		sec += 1
		i += 8
	else:
		assert False

if big != sec : print("bigdata?" if big > sec else "security!")
else : print("bigdata? security!")