import sys
I = lambda : sys.stdin.readline().strip()

n = int(I())
dices = list(map(int, I().split()))
reward = [0,0,0,0]
cur_score = 0 # 현재 얻은 점수
get_score = 1 # 주사위 굴릴때마다 얻는 점수
cur_time = 0 # 현재 흐른 시간
get_time = 4 # 주사위 굴릴때마다 흐르는 시간
flag = False

def init():
	global cur_score, get_score, cur_time, get_time
	cur_score = 0
	get_score = 1
	cur_time = 0
	get_time = 4

def get_reward(score) :
	global reward
	if 35 <= score < 65 : reward[0] += 1
	elif 65 <= score < 95 : reward[1] += 1
	elif 95 <= score < 125 : reward[2] += 1
	elif 125 <= score : reward[3] += 1

for dice in dices :
	if cur_time > 240 or flag:
		flag = False
		get_reward(cur_score)
		init()

	if dice == 1:
		flag = True
		get_reward(cur_score)
		init()

	elif dice == 2:
		if get_score > 1 :
			get_score /= 2
		elif get_score == 1 :
			get_time += 2

	elif dice == 4:
		cur_time += 56

	elif dice == 5:
		if get_time > 1:
			get_time -= 1

	elif dice == 6:
		if get_score < 32:
			get_score *= 2

	cur_score += get_score
	cur_time += get_time

if flag : get_reward(cur_score)
print(*reward, sep='\n')