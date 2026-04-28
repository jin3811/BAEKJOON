n = int(input())
cards = list(map(int, input().split()))
ans = cards[0]
l, r = 0, 1

while r < n:
	if cards[r] - cards[l] != r - l:
		l = r
		ans += cards[l]
	r += 1
print(ans)