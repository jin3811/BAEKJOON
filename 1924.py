t=[31,28,31,30,31,30,31,31,30,31,30,31]
a=["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
m,d=map(int, input().split())
print(a[(sum(t[:m-1]) + d)%7])