import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

dp = [0,1,2,3]
tc = int(sys.stdin.readline().strip())

for _ in range(tc):
	for i, m in enumerate(I()):
		if i >= len(dp):
			dp.append(sum(dp[i-4:i]))
		if m != dp[i] :
			print("SNAIL")
			break
	else:
		print("NAUTILUS")