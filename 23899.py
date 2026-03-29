n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(n-1, 0, -1):
	if a == b :
		print(1)
		exit(0)
	idx = a.index(max(a[:i+1]))
	if idx != i:
		a[idx], a[i] = a[i], a[idx]

print(int(a == b))

# a = list(range(10))
# print(a[:2])