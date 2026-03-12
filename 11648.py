n=int(input())
ans = 0
while n >= 10:
	ans += 1
	tmp = 1
	while n > 0:
		tmp *= n % 10
		n //= 10
	n = tmp
print(ans)