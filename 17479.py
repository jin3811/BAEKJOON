import sys
I = lambda:sys.stdin.readline().strip()
a, b, c = map(int, I().split())

normal = {}
special = {}
service = []
normal_cost = 0
special_cost = 0
service_cost = 0

def sortKey(x) :
	if x in normal.keys(): return 0
	if x in special.keys(): return 1
	return 2

for _ in range(a):
	name, cost = I().split()
	normal[name] = int(cost)

for _ in range(b):
	name, cost = I().split()
	special[name] = int(cost)

for _ in range(c):
	service.append(I())

n = int(I())

for menu in map(lambda x : x.strip(), sys.stdin.readlines()):
	if menu in normal.keys():
		normal_cost += normal[menu]
	elif menu in special.keys():
		special_cost += special[menu]
	else:
		service_cost += 1

if special_cost > 0 and normal_cost < 20000:
	print("No")
elif service_cost > 0 and normal_cost + special_cost < 50000:
	print("No")
elif service_cost > 1:
	print("No")
else :
	print("Okay")