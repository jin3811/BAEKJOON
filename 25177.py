import sys
I=lambda:map(int,sys.stdin.readline().split())
n, m = I()
curr = list(I()) + [0] * (m - n)
prev = list(I()) + [0] * (n - m)
print(max([p-c for c,p in zip(curr,prev)]+[0]))