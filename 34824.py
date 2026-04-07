for r in open(0).readlines()[1:]:
	r = r.strip()
	if r == "yonsei":
		print("Yonsei Won!")
		break
	elif r == "korea":
		print("Yonsei Lost...")
		break