n = int(input())
ans = 1
while n >= (10**(ans+1) - 1)//9 : ans += 1
print(ans)