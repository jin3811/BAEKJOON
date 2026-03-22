import string

plain, crypt = [[ord(i) for i in input()] for _ in range(2)]

for i, v in enumerate(plain):
	print(string.ascii_lowercase[v - crypt[i % len(crypt)] - 1] if v != 32 else " ", end='')