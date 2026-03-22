import sys
I=sys.stdin.readline

n, winner = I().split()
log = []

for _ in range(int(n)):
	name, chat = I().split()
	if name == winner : 
		print(log.count(chat))
		break
	log.append(chat)