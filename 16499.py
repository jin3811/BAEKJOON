import sys
print(len(set(map(lambda x : "".join(sorted(x.rstrip())), sys.stdin.readlines()[1:]))))