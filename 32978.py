import sys
I=lambda:sys.stdin.readline().strip().split()

I()
recipe = I()
for i in I():
    recipe.remove(i)
print(*recipe)