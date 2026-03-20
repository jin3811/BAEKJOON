"""
- 일반적인 에라토스테네스의 체
- 아이디어도 간단하고, 구현도 빠르지만, 같은 합성수(ex. 210 = 2*3*5*7)를 여러번 반복 방문하기에 조금 비효율적
- Time Complexity = O(NloglogN)
"""
def eratos_seive():
    MAX = 10**4+1
    seive = [1] * MAX # 체
    seive[0] = seive[1] = 0

    for i in range(2, MAX):
        if seive[i]:
            j = 2
            while i * j < MAX:
                seive[i*j] = 0
                j += 1

"""
- 선형 체, 오일러 체라고도 한다.
- 에라토스테네스의 체에서 같은 합성수의 중복 방문을 없애 보다 더 효율적인 방식
- 선형 체는 소수 판정 뿐만 아니라, 곱셈적 함수 등 다양한 부분에서 사용 가능하다. 추후 공부가 필요할 듯.
- Time Complexity = O(N)
- https://p4per.dev/posts/Linear-Sieve/#선형-체-linear-sieve
- 챗지피티 - 알고리즘
- 이해 못했던 부분 : 왜 탐색 범위를 p|q, q%p == 0인 부분까지만 할까?
-> lpf(n) <= lpf(q) 인건 자명하다. 또한, 우리는 p와 q를 결정하여 n을 만든다. 우리가 코드를 돌릴땐 lpf(q)를 모르고 돌리는 상태. 만약 p < lpf(q)라면 q%p != 0이다. p == lpf(q)라면 q % p == 0이고, lpf(n) == lpf(q) == p이다. 그런데, 다음 소수인 p > lpf(q)를 따지게 되면, lpf(n)은 p가 아닌 lpf(q)가 된다. 이는 lpf(q)를 기준으로 체를 할 때 이미 방문했다는 뜻이다. 선형 체의 기초 원리에 위배됨. 따라서 p|q인 지점까지만 탐색을 하면 된다.
"""
def linear_seive():
    MAX = 10**4+1
    seive = [1] * MAX # 체
    seive[0] = seive[1] = 0
    prime = [] # [2, MAX) 내의 소수 배열

    for q in range(2, MAX):
        if seive[q] :
            prime.append(q)

        for p in prime :
            if q*p >= MAX: break
            seive[q*p] = 0
            if q % p == 0: break

# lpf 배열을 같이 구해야할 때, 사용하면 좋다.
def linear_seive_with_lpf():
    MAX = 10**4+1
    prime = [] # [2, MAX) 내의 소수 배열
    lpf = [0] * MAX # least prime factor, lpf(n) : n의 최소 소인수.

    for q in range(2, MAX):
        if lpf[q] == 0:
            lpf[q] = q
            prime.append(q)

        for p in prime :
            if q*p >= MAX: break
            lpf[q*p] = p
            if q % p == 0: break
