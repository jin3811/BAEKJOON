import sys
import math

def input() : return sys.stdin.readline().strip()

w, h = map(int, input().split())
x, y = map(int, input().split())

mod = 1000007
h2t = math.comb(x + y - 2, min(x, y) - 1)
t2s = math.comb(w + h - x - y, min(w - x, h - y))
print(((h2t * t2s)) % mod)