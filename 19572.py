ab, ca, bc = map(int, input().split())
b = (ab - ca + bc) / 2
a, c = ab - b, bc - b
print(-1 if min(a, b, c) <= 0 else f"1\n{a:.1f} {b:.1f} {c:.1f}")