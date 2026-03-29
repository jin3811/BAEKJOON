c=[1,5,10,50]
n=int(input())
ans=0
for _ in range(n):
	ans+=c[(int(input()[:3])-136)//6]*1000
print(ans)