import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

def dot_pd(p1, p2) :
	res = 0
	for i in range(2):
		res += p1[i] * p2[i]
	return res

def vector_norm_square(v):
	res = 0
	for i in range(2):
		res += v[i] ** 2
	return res

a, b, c = [list(I()) for _ in range(3)]

vab = [b[i]-a[i] for i in range(2)]
vbc = [c[i]-b[i] for i in range(2)]
vca = [a[i]-c[i] for i in range(2)]

nab = vector_norm_square(vab)
nbc = vector_norm_square(vbc)
nca = vector_norm_square(vca)

same = len(set([nab, nbc, nca]))

# 정수 점으로는 정삼각형을 만들 수 없다.
if dot_pd(vab, vbc) ** 2 == nab * nbc:
	print("X")
elif same == 2:
	cos = sorted([nab, nbc, nca])
	if cos[0] < cos[1]:
		print("Yeahkak2Triangle")
	elif cos[0]+cos[1] == cos[2] :
		print("Jikkak2Triangle")
	else :
		print("Dunkak2Triangle")
else :
	cos = sorted([nab, nbc, nca])
	if cos[0] + cos[1] > cos[2]:
		print("YeahkakTriangle")
	elif cos[0] + cos[1] == cos[2] :
		print("JikkakTriangle")
	else :
		print("DunkakTriangle")
