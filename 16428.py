import sys
a, b = map(int, sys.stdin.readline().split())

c, d = a//b, a%b

if b < 0:
    if d != 0:
        print(c + 1)
        print(d - b)
    else :
        print(c)
        print(d)
else :
    print(c)
    print(d)