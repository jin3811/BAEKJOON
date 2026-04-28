import sys
inp = sys.stdin.readline

sol = {
	"black" : 0,
	"brown" : 1,
	"red" : 2,
	"orange" : 3,
	"yellow" : 4,
	"green" : 5,
	"blue" : 6,
	"violet" : 7,
	"grey" : 8,
	"white" : 9
}

a=sol[inp().strip()]
b=sol[inp().strip()]
c=sol[inp().strip()]
print(int(f"{a}{b}{'0'*c}"))