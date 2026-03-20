import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

MAX = 5*10**6+1
prime = []
lpf = [0] * MAX

for q in range(2, MAX):
	if lpf[q] == 0:
		lpf[q] = q
		prime.append(q)

	for p in prime :
		if q*p >= MAX: break
		lpf[q*p] = p
		if q % p == 0: break

next(I())
for n in I():
	while n > 1:
		print(lpf[n], end=' ')
		n //= lpf[n]
	print()