"""
 * 짝 짝 -> 젤 처음 한장 찍고 나머지 두장씩
 * 짝 홀 -> 젤 처음 한장, 맨 마지막 홀장 빼고 두장씩, 그리고 맨 마지막
 * 홀 짝 -> 두장씩
 * 홀 홀 -> 두장씩 찍다가, 맨 마지막 한장
 * 맨 처음 짝수 = 한장 찍고 다음 페이지 넘어가야 함
 * 맨 마지막 홀수 = 딱 한장남음
"""

import sys
def input() : return sys.stdin.readline().strip()
st, ed = map(int, input().split())

res = 0
if st % 2 == 0: # 맨 처음 짝수
    res += 1
    st += 1
if ed % 2 == 1 : # 맨 마지막 홀수
    res += 1
    ed -= 1
res += (ed - st + 1) // 2
print(res)