import sys
n, k = map(int, sys.stdin.readline().split())

if k == 0 : 
	print(*range(1, n + 1))
else :
	ans = [0] * n
	num = n
	while k > 0:
		for i in range(num):
			if k == 0 or i == num - 1:
				ans[i] = num
				break
			k -= 1
		num -= 1

	ans.reverse()

	num = 1
	for i in range(n):
		if ans[i] == 0 : 
			ans[i] = num
			num += 1

	print(*ans)