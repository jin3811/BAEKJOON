n = int(input())

for i in range(1, n + 1):
	line = " " * (2 * n - i) + "*"
	line += " " * n + "*"
	line += " " * (2 * i - 1) + "*"
	line += " " * (4*n + 2 - len(line))
	print(line)

for i in range(1, n + 1):
	line = " " * (n - i) + "*"
	line += " " * (n + 1 + 2*(i-1)) + "*"
	line += " " * (2 * (n - i) + 1) + "*"
	line += " " * (4*n + 2 - len(line))
	print(line)