from collections import deque
import sys
I = lambda: map(int, sys.stdin.readline().split())

n, m = I()
deck = [deque() for _ in range(2)]
ground = [deque() for _ in range(2)]

for _ in range(n):
	d, s = I()
	deck[0].append(d), deck[1].append(s)

def is_game_end() :
	# return len(do_deck) * len(su_deck) == 0
	return not (deck[0] and deck[1])

def card_flip(player: int) :
	ground[player].append(deck[player].pop())

def bell_ring(winner: int) :
	loser = 1 - winner
	deck[winner].extendleft(ground[loser])
	deck[winner].extendleft(ground[winner])
	ground[winner].clear(), ground[loser].clear()

def check_ring():
	if (ground[0] and ground[0][-1] == 5) or (ground[1] and ground[1][-1] == 5):
		bell_ring(0)

	elif ground[0] and ground[1] and ground[0][-1] + ground[1][-1] == 5:
		bell_ring(1)

for turn in range(m):
	card_flip(turn % 2)
	if is_game_end():
		break
	check_ring()

dl = len(deck[0])
sl = len(deck[1])

if dl > sl: print("do")
elif dl < sl: print("su")
else: print("dosu")