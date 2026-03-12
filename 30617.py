import sys

ans = 0
knob = list(map(lambda x : x.strip().split(), sys.stdin.readlines()[1:]))

for i in range(len(knob)):
	if i :
		for k in range(2):
			if knob[i][k] != "0" and knob[i][k] == knob[i-1][k]:
				ans += 1
	if "".join(knob[i]) != "00" and knob[i][0] == knob[i][1]:
		ans += 1

print(ans)