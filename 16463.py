_t = [0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4]
def sakamoto(y, m, d):
	global _t
	y -= m < 3
	return (y + y//4 - y//100 + y//400 + _t[m-1] + d) % 7

ans = 0
for y in range(2019, int(input())+1):
	for m in range(1, 13):
		ans += sakamoto(y, m, 13) == 5
print(ans)
