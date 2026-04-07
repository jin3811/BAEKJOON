n = int(input())
ans = 0
i = 1
exp = 0

while i <= n:
	if n & i : ans += 3**exp
	i <<= 1
	exp += 1
print(ans)