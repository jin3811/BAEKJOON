import sys
l, r = map(int,sys.stdin.readline().split())
ml, mr = 0, 0
while l != 1 and r != 1:
	if l < r :
		r -= l
		mr += 1
	elif l > r:
		l -= r
		ml += 1
	else:
		assert False

if r == 1:
	ml += l - 1
else :
	mr += r - 1

print(ml, mr)