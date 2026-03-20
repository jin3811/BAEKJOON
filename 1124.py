import sys

MAX = 10**5+1

lpf = [0] * MAX
prime = []

for q in range(2, MAX):
	if lpf[q] == 0:
		lpf[q] = q
		prime.append(q)

	for p in prime :
		if q*p >= MAX: break
		lpf[q*p] = p
		if q % p == 0: break

dp = [-1] * MAX
def up(x) :
	if lpf[x] == x: 
		dp[x] = 1
		return dp[x]

	if dp[x] != -1:
		return dp[x]

	dp[x] = up(x//lpf[x]) + 1
	return dp[x]

a, b = map(int,sys.stdin.readline().strip().split())

ans = 0
for i in range(a, b + 1):
	fac = up(i)
	if lpf[fac] == fac:
		ans += 1
print(ans)