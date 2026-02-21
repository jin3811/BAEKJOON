import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

while True:
    a,b=I()
    if a == b == 0: break
    print(a+b)