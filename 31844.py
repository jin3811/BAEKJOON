ctp=input()
r, b, f = (ctp.index(i) for i in"@#!")
if r<b<f or r>b>f: print(abs(f-r)-1)
else: print(-1)