import sys
input = sys.stdin.readline

tc = int(input().strip())

for _ in range(tc):
	len = input().strip()
	nums = list(map(int, input().strip().split()))
	print(f"{min(nums)} {max(nums)}")