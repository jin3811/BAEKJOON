a = list(map(int, input().split()))
b = list(map(int, input().split()))

ma,se,ye = [b[0]-a[0]] * 3
se += 1
ma -= (a[1],a[2]) > (b[1],b[2])

print(ma,se,ye,sep='\n')