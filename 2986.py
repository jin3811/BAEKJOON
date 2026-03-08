def is_prime(n : int):
	# if n <= 1: return False # 편의상 뺌
	if n == 2 : return True

	fac = 2
	while fac ** 2 <= n:
		if n % fac == 0:
			return False
		fac += 1

	return True

n = int(input())
if is_prime(n):
	print(n - 1)
else:
	for i in range(2, int(n ** 0.5) + 1):
		if n % i == 0:
			print(n - n//i)
			break
