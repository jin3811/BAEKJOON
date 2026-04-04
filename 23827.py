import sys
I=sys.stdin.readline

MOD = 1000000007
ans = 0
n = int(I())
a = list(map(int,I().split()))
b = [a[n-i-1] for i in range(n)]

for i in range(1, n-1):
	b[i] += b[i-1]
b.reverse()

for i, v in enumerate(b[1:]):
	ans += int(a[i]*v)%MOD
	ans %= MOD

print(ans)