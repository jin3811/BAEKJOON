import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

I()
dices = I()
stu = []

for i, dice in enumerate(dices):
    stu.insert(len(stu)-dice, i+1)

print(*stu)