import sys

rank_table = sorted(map(lambda x : x.strip().split(), sys.stdin.readlines()))
r, b = 0, 0
score = [10,8,6,5,4,3,2,1]

for i, team in enumerate(rank_table):
	if team[1] == 'B':  b += score[i]
	else: r += score[i]

print('Blue' if r < b else 'Red')