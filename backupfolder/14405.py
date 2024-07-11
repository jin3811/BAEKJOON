a = input()
a = a.replace("pi", " ")
a = a.replace("ka", " ")
a = a.replace("chu", " ")

print("YES" if a.strip() == "" else "NO")