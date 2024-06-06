import sys
def input() : return sys.stdin.readline().strip()

def dec2base(dec, base):
	res = ''
	while dec > 0:
		dec, mod = divmod(dec, base)
		if mod < 10:
			res += str(mod)
		elif mod < 36:
			res += chr(ord("a") + mod - 10)
			
	padding = "a" * (13 - len(res))

	return padding + res[::-1]

def base2dec(num, base):
	res = 0
	for i in num:
		res *= base
		if ord("0") <= ord(i) <= ord("9"):
			res += int(i)

		elif ord("a") <= ord(i) <= ord("z"):
			res += int(ord(i) - ord("a") + 10)
		
	return res

t = int(input())
if t == 1:
	print(dec2base(sum(map(int, input().split())), 26))
elif t == 2:
	print(base2dec(input(), 26))