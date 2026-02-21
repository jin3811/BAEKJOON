import sys

for tc in sys.stdin:
	a,b,c = sorted(map(int, tc.strip().split()))
	print(max(b-a, c-b)-1)