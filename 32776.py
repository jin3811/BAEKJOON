import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

hsr = next(I())
fli = sum(I())

print("high speed rail" if hsr <= fli or hsr <= 240 else "flight")