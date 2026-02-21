import sys
I=lambda:map(int,sys.stdin.readline().strip().split())

A,B,C = I()

R2 = range(1, 11)

if A == 0:
    # By = C => y = C/B, x축 평행
    # g2g = list(map(lambda x : x.append(C // B if (C % B == 0 and C // B in R2) else 0), g2g))
    
    g2g = [[C//B] if C % B == 0 and C // B in R2 else 0 for _ in R2]

elif B == 0:
    # Ax = C => x = C/A, y축 평행
    # for x in g2g:
    #     x.append(0)
    g2g = [[0] for _ in R2]
    if C % A == 0 and C // A in R2 :
        g2g[C // A - 1] = list(R2)

else:
    # Ax+By=C => y = (C-Ax)/B
    g2g = [[] for _ in R2]
    for x in R2:
        bunja = C - A*x
        g2g[x - 1].append(bunja // B if bunja % B == 0 and bunja // B in R2 else 0)

for y in g2g:
    if not y : print(0)
    else : print(*y)