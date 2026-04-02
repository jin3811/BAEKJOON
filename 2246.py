n, *condos = open(0).readlines()
n = int(n)
ans = n
condos = sorted(map(lambda x : list(map(int,x.split())), condos))

for i in range(n):
	x = condos[i][1]
	for j in range(n):
		if j < i and x >= condos[j][1] : 
			ans -= 1
			break
print(ans)