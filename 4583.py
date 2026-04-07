for s in map(lambda x : x.strip()[::-1], open(0).readlines()[:-1]):
	ans = ""
	for i in s:
		if i in "bd":
			ans += "d" if i == "b" else "b"
		elif i in "pq":
			ans += "p" if i == "q" else "q"
		elif i in "iovwx":
			ans += i
		else :
			ans = "INVALID"
			break
	print(ans)