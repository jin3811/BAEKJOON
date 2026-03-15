"""
(e^x)sin(x)cos(x) = (e^x)sin(2x)/2 로 바꾼 후, 미분하다보면 해당 점화식이 보인다.

덧셈법칙으로 바꾸면 보이는 것이 an + bn = 0이고(코사인 덧셈법칙), cn = ESC^0(x)의 계수이다.
ESC^0(x) = (e^x)sin(2x)/2
ESC^1(x) = ESC^0(x) + (e^x)cos(2x)
ESC^2(x) = ESC^1(x) + (e^x)cos(2x) - 2(e^x)sin(2x)
         = ESC^0(x) + (e^x)cos(2x) + (e^x)cos(2x) - 4ESC^0(x)
		 = -3ESC^0(x) + 2(e^x)cos(2x)
"""
ans = [1, 1]
for _ in range(1, int(input())):
	c, a = ans
	ans = [c - 4*a, c+a]
print(ans[0])