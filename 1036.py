import sys
import string

I=lambda:sys.stdin.readline().strip()

tmp = string.digits+string.ascii_uppercase
def dec_to_base(n, b) :
	q, r = divmod(n, b)
	if q == 0 : return tmp[r]
	else : return dec_to_base(q, b) + tmp[r]

n = int(I())
nums = [I() for _ in range(n)]
k = int(I())
g = {}

for num in nums:
	for n, b in enumerate(num[::-1]):
		if b in g : g[b] += 36**n
		else : g[b] = 36**n

nums = sorted(g.items(), key=lambda x : x[1], reverse=True)
nums = sorted(g.items(), key=lambda x : (tmp.find(x[0]) - 35) * x[1])

n = 0
idx = 0

while idx < k and idx < len(nums):
	n += 35 * nums[idx][1]
	idx += 1

while idx < len(nums) :
	n += tmp.find(nums[idx][0]) * nums[idx][1]
	idx += 1

print(dec_to_base(n, 36))