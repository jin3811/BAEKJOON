import sys
I = lambda : sys.stdin.readline().strip()

n, m = map(int, I().split())
u, v = map(int, I().split())

texture = [I() for i in range(u)]

query = I()

if query[0] == 'c':
	texture = list(map(
		lambda x : x + x[v - 1] * (m - v),
		texture
	))

	while len(texture) < n:
		texture.append(texture[u - 1])

elif query[0] == 'r':
	texture = list(map(lambda x : x * (m // v + 1), texture)) * (n // u + 1)

else :
	for ty in range(u):
		texture[ty] += texture[ty][::-1]
		texture[ty] *= m // v + 1
	
	texture += texture[::-1]
	texture *= n // u + 1

print(*(map(lambda x : x[:m], texture[:n])), sep='\n')