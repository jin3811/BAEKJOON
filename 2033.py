n = int(input())
exp = 1

while n >= 10**exp:
	n += 5 * 10**(exp-1)
	n = n//(10**exp) * (10**exp)
	exp += 1

print(n)