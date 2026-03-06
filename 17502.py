import sys
n, pal = map(lambda x : x.strip(), sys.stdin.readlines())
ans = ""

for i in range(int(n)):
	if pal[i] == pal[::-1][i] == "?": ans += "a"
	else: ans += pal[i] if pal[i] != "?" else pal[::-1][i]
print(ans)