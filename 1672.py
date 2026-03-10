import sys
I=lambda:sys.stdin.readline().strip()

base = {"A" : 0, "G" : 1, "C" : 2, "T" : 3}

decode = [
	["A", "C", "A", "G"],
	["C", "G", "T", "A"],
	["A", "T", "C", "G"],
	["G", "A", "G", "T"]
]

n = int(I())-2
nuc = [i for i in I()]

while n >= 0:
	nuc[n] = decode[base[nuc[n]]][base[nuc[n + 1]]]
	n -= 1

print(nuc[0])