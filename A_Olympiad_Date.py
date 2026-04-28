import sys
I = lambda : sys.stdin.readline().strip()

date={0:3,1:1,2:2,3:1,5:1}
keys = list(date.keys())
tc=int(I())

while tc :
	tc -= 1
	comb={0:0,1:0,2:0,3:0,5:0}
	flag = True
	n = int(I())
	d = list(map(int, I().split()))

	for i in range(len(d)):
		if d[i] in keys:
			comb[d[i]] += 1
		
		for k in keys:
			if date[k] > comb[k]:
				break
		else:
			print(i + 1)
			flag = False
			break

	if flag: print(0)