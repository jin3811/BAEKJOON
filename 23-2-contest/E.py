import sys
input = sys.stdin.readline

tc = int(input())
for i in range(1, tc + 1):
    answer = 0
    n = int(input())
    v = list(map(int, input().split(' ')))
    
    for x in range(0, len(v) - 1):
        for y in range(x + 1, len(v)):
            if v[x] + v[y] == 196:
                answer += 1
    
    print(f"Case #{i} : {answer}")