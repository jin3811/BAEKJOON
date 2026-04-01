import sys
from types import GeneratorType

I=sys.stdin.readline

# def bootstrap(f, stack=[]):
# 	def wrappedfunc(*args, **kwargs):
# 		if stack:
# 			return f(*args, **kwargs)
# 		else:
# 			to = f(*args, **kwargs)
# 			while True:
# 				if type(to) is GeneratorType:
# 					stack.append(to)
# 					to = next(to)
# 				else:
# 					stack.pop()
# 					if not stack:
# 						break
# 					to = stack[-1].send(to)
# 			return to
# 	return wrappedfunc

# @bootstrap
def bact(num=0):
	global n, k, ans
	if num > n:
		# yield
		return
	if num <= n:
		ans = max(num, ans)
		# yield
		# return

	for i in k:
		bact(10*num + i)
	# 	yield bact(10*num + i)
	# yield

n = int(I().split()[0])
k = list(map(int, sorted(I().split())[::-1]))
ans = -1
bact()
print(ans)