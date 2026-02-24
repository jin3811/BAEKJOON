import sys
print(100*min(map(lambda x : int(x.strip()), sys.stdin.readlines()))//2)