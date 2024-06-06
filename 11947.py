import sys
def input() : return sys.stdin.readline().strip()
pow = lambda x : 10**x

for _ in range(int(input())):
	answer = []
	a = input()
	num_len = len(a)
	num_a = int(a)

	for i in range(1, num_len):
		answer.append((pow(i) // 2) * (pow(i) // 2 - 1))
	
	if num_a >= 10**num_len // 2 + 1:
		answer.append((pow(num_len) // 2) * (pow(num_len) // 2 - 1))
	else :
		answer.append(num_a * (pow(num_len) - num_a - 1))

	print(max(answer))