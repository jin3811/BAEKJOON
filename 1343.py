poly = input().split('.')

for i, xx in enumerate(poly):
	if not xx : continue

	if len(xx) % 2 != 0:
		print(-1)
		exit()

	repl = "AAAA" * (len(xx) // 4) + "BB" * (len(xx) // 2 % 2)
	poly[i] = repl

print('.'.join(poly))