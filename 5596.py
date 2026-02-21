import sys
I=lambda:map(int,sys.stdin.readline().strip().split())
print(max(sum(I()),sum(I())))