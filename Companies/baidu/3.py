# KMP
# given two sting A and B, and two index: l, r, return how many word B in A[l:r]
# eg:
# comeonmandontconconnect
# on
# 5
# 1 5
# 1 6
# 1 23
# 11 16
# 11 23
#
# output:
# 0
# 1
# 4
# 2
# 3

import sys

A = sys.stdin.readline().strip()
B = sys.stdin.readline().strip()
Q = int(sys.stdin.readline())

len_B = len(B)
hit = [0 for a in A]
for i in range(len(A)):
	if A[i:i+len_B] == B:
		hit[i+len_B-1] = 1

left = [0 for a in A]
right = [0 for a in A]

num = 0
for i in range(len(A)):
	num += hit[i]
	left[i] = num

for q in range(Q):
	row = sys.stdin.readline().strip()
	l, r = row.split()
	l = int(l) - 1
	r = int(r) - 1

	res = left[r] - left[l] + hit[l]
	for i in range(l, l+len_B-1):
		if (i <= r):
			res -= hit[i]

	print(res)