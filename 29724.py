import sys
I=sys.stdin.readline

tw, tc = 0, 0
for _ in range(int(I())):
	t, w, h, l = I().split()

	if t == "B":
		tw += 6000
	elif t == "A":
		w,h,l = map(lambda x : int(x)//12, (w,h,l))
		tmp = w*h*l
		tw += 1000 + tmp*500
		tc += tmp*4000
print(tw,tc,sep='\n')