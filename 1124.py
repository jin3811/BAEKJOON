import sys

p = list(range(317))
p[0] = p[1] = 0
for i in range(2, int(len(p) ** 0.5) + 10):
	if p[i] :
		j = 2
		while i * j < len(p):
			p[i*j] = 0
			j += 1
p = list(filter(lambda x : x, p))

def under_prime(x) :
	if x in p : return False
	ans = 0
	for i in range(2, int(x ** 0.5) + 1):
		if x % i == 0:
			while x % i == 0:
				ans += 1
				x //= i
	if x > 1: ans += 1
	return ans in p

a, b = map(int,sys.stdin.readline().strip().split())
print(len(list(filter(lambda x : under_prime(x), range(a, b+1)))))