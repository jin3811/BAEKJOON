import sys
I=lambda:int(sys.stdin.readline().strip())

tc = I()
coin = (25, 10, 5, 1)
for _ in range(tc):
    m = I()
    for c in coin:
        print(f"{m // c}", end=' ')
        m %= c
    print()