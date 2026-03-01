n, k = map(int, input().strip().split())
ans = -1
for i in range(1,k+1):
	ans = max(ans, int((str(n*i)[::-1])))
print(ans)