sh,sm = map(int,input().split())
eh,em = map(int,input().split())
n = input()
ans = 0
while True:
	ans += n in f"{sh:02}{sm:02}"
	if sh == eh and sm == em : break
	sm = (sm + 1)%60
	if sm == 0 : sh += 1
print(ans)