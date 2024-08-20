import sys
def input() : return sys.stdin.readline().strip()

n=int(input())
arr=sorted(list(map(int, input().split())))
cnt = 0

for i in range(n):
    l,r = 0,n-1
    while l < r:
        if l == i:
            l += 1
            continue
        elif r == i:
            r -= 1
            continue
        
        cur = arr[l] + arr[r]
        if cur == arr[i]:
            cnt += 1
            break
        elif cur < arr[i]:
            l+=1
        else:
            r-=1
print(cnt)