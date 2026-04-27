"""
n개의 지역 리그, 지역 리그당 m개의 팀
같은 지역 리그 팀당 경기수 : A (A >= 1)
다른 지역 리그 팀당 경기수 : B (B >= 1)
필수 조건 : A = kB

구해야 하는 것
- 최대 경기 횟수 d 이하이면서, d에 가장 근접하도록, 동시에 A=kB 조건 만족하도록 전체 경기수
- 전체 경기수 = 한 리그에서 발생하는 같은 지역 리그 경기수+ 타 리그 팀과의 총 경기횟수
한 리그에서 발생하는 같은 지역 리그 경기수 = mC2 * n * A
타 리그 팀과의 경기 수 = n(n-1)m^2 * b

조건을 통해 알 수 있는 것
A = kB이며 k는 변하지 않기 때문에, A나 B 둘중 하나만 정해도 다른 한쪽이 정해진다

b <= 2d/nm(k(m-1)+m(n-1))
총 경기수 = (anm(m-1)+bm^2n(n-1))/2 = (kbnm(m-1)+bm^2n(n-1))/2
"""

import sys
I=sys.stdin.readline

for _ in range(int(I())):
	n, m, k, d = map(int, I().split())

	b = (n * m * (k * (m - 1) + m * (n - 1)))
	max_b = 2 * d // b
	print(max_b * b // 2 if max_b else -1)