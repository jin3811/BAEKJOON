ans = 0
for s in input():
	if s == "KOREA"[ans%5]:
		ans += 1
print(ans)