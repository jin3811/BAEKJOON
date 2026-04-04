a=input()
if len(a) == 4:
	print(20)
elif len(a) == 3:
	print(*sorted(a)[1:],sep='')
else :
	print(int(a[0]) + int(a[1]))