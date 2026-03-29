import string
while True:
	s = input()
	if s == "*" : break

	print("Y" if "".join(sorted(list(set(s.replace(" ", ""))))) == string.ascii_lowercase else "N")